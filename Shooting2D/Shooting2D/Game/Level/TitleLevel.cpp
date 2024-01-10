#include "DxLib.h"
#include "Game/Level/TitleLevel.h"
#include "Game/Level/LevelChanger.h"
#include "System/Input/InputManager.h"

/// <summary>
/// TitleLevel.cppのみで使用する定数
/// </summary>
namespace {

  /// <summary>
  /// 背景画像
  /// </summary>
  const char* kTitleBgImageFilePath = "Assets/Image/Title/TitleBg01.png";

  /// <summary>
  /// 背景画像のX座標
  /// </summary>
  const int kBgPosX = 200;

  /// <summary>
  /// レベルの切り替え時間
  /// </summary>
  const float kChangeLevelTime = 3.0f;

  /// <summary>
  /// 切り変え時間
  /// </summary>
  const float kChangeTitle = 1.2f;

  /// <summary>
  /// フェードインの時間
  /// </summary>
  const float kFadeInTime = 0.5f;

  /// <summary>
  /// フェードアウト時間
  /// </summary>
  const float kSoundFade = 1.0f;
}

/// <summary>
/// コンストラクタ
/// </summary>
TitleLevel::TitleLevel()
  : title_level_state_(TitleLevelState::kNone)
  , title_bg_handle_(0)
  , elapsed_time_(0.0f)
  , z_pressed_(false){

}

/// <summary>
/// デストラクタ
/// </summary>
TitleLevel::~TitleLevel() {
  
}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void TitleLevel::Update(float delta_time) {


  ///何もしない状態なら実行しない
  if (title_level_state_ == TitleLevelState::kNone) {
    
    return;
  }
  if (!fade_out_) {
    FadeManager::GetInstance()->StartFadeIn(kFadeInTime);
    FadeManager::GetInstance()->Update(delta_time);
  }
  audio_manager_->FadeInBgm(kSoundFade);
  
  //タイトル点滅
  title_ui_->Update(delta_time);

  //zを押したら
  if (InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kPlayerFire)) {
    if (!z_pressed_) {
      
      audio_manager_->PlaySe(AudioManager::EffectKind::kTitleStartEffect);
    }
    
    z_pressed_ = true;
    
  }
  
  //zを押したら
  if (z_pressed_ == true) {
    audio_manager_->StopBgm();
    // 経過時間を計算
    elapsed_time_ += delta_time;
    //ガイダンスロゴを拡大
    
    title_ui_->CheckZoom();
    
    //フェードアウト
    
    if (!fade_out_) {
      FadeManager::GetInstance()->StartFadeOut(kChangeTitle);
      fade_out_ = true;  
    }
    
    FadeManager::GetInstance()->Update(delta_time);
    //0.8秒後に開始
    if (elapsed_time_ > kChangeTitle) {
     
      // 状態を何もしないへ
      title_level_state_ = TitleLevelState::kNone;
      
      LevelChanger::GetInstance()->SetLevelChangerState(LevelChanger::LevelChangerState::kFinTitleLevel);
   
    }

  }
}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void TitleLevel::Render() {
  //背景
  DrawGraph(kBgPosX, 0, title_bg_handle_, TRUE);
  //タイトル
  title_ui_->Render();
  //サイド
  side_ui_->Render();
    
}

/// <summary>
/// レベルの開始処理
/// </summary>
void TitleLevel::BeginLevel() {

  //背景読み込み
  title_bg_handle_ = LoadGraph(kTitleBgImageFilePath);

  
  //状態を通常へ
  title_level_state_ = TitleLevelState::kPlay;

  //クラスのインスタンス生成
  title_ui_ = new TitleUi;
  side_ui_ = new SideUi;
  audio_manager_ = new AudioManager();

  FadeManager::GetInstance()->Initialize();

  //クラスの初期化
  title_ui_->Initialize();
  side_ui_->Initialize();

  audio_manager_->LoadBgm();
  audio_manager_->PlayBgm(AudioManager::BgmKind::kTitleBgm);
  audio_manager_->LoadSe();
}

/// <summary>
/// タイトルレベルの管理するものをタスクマネージャーから解放する
/// </summary>
void TitleLevel::ReleaseLevel() {

  TaskManager::GetInstance()->ReleaseTask(title_ui_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(side_ui_->GetTaskId());
}

/// <summary>
/// タイトルレベルの管理するものを破棄
/// </summary>
void TitleLevel::DestroyLevel() {

  //背景画像破棄
  DeleteGraph(title_bg_handle_);

  //タイトルUIの破棄
  title_ui_->DestroyTitleUi();
  delete title_ui_;
  title_ui_ = nullptr;

  //サイドUIの破棄
  side_ui_->DestroySideUi();
  delete side_ui_;
  side_ui_ = nullptr;

  audio_manager_->DeleteBgm();
  audio_manager_->DeleteSe();
  delete audio_manager_;
  audio_manager_ = nullptr;
}