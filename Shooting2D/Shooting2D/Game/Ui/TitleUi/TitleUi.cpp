#include "TitleUi.h"
#include "DxLib.h"
#include "System/Input/InputManager.h"
#include "Game/FadeManager/FadeManager.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// タイトルロゴ
  /// </summary>
  const char* kTitleUiImageTitle = "Assets/Image/Ui/TitleUi/TitleLogo01.png";

  /// <summary>
  /// タイトルガイダンスロゴ
  /// </summary>
  const char* kTitleUiImageGidance = "Assets/Image/Ui/TitleUi/TitleGuidance01.png";

  /// <summary>
  /// ロゴｘ座標
  /// </summary>
  const int kLogoX = 350;

  /// <summary>
  /// ロゴｙ座標
  /// </summary>
  const int kLogoY = 150;

  /// <summary>
  /// ガイダンスｘ座標
  /// </summary>
  const int kGuidanceX = 460;

  /// <summary>
  /// ガイダンスｙ座標
  /// </summary>
  const int kGuidanceY = 500;

  /// <summary>
  /// 点滅時間
  /// </summary>
  const float kShowGuidance = 0.7f;

  /// <summary>
  /// 拡大していく
  /// </summary>
  const float kZoom = 0.02f;

  /// <summary>
  /// ロゴフェード時間
  /// </summary>
  const float kLogoFade = 0.5f;

  /// <summary>
  /// ズーム倍率
  /// </summary>
  const float kZooMFactor = 1.0f;

  const int kHalf = 2;
}
/// <summary>
/// コンストラクタ
/// </summary>
TitleUi::TitleUi()
  : title_ui_logo_image_()
  , title_ui_guidance_image_()
  , title_logo_width_()
  , title_logo_height_()
  , title_guidance_width_()
  , title_guidance_height_()
  , logo_x_()
  , logo_y_()
  , guidance_x_()
  , guidance_y_()
  , show_guidance_(true)
  , elapsed_time_(0.0f)
  , zoom_factor_(kZooMFactor) {

}

/// <summary>
/// デストラクタ
/// </summary>
TitleUi::~TitleUi() {
}

/// <summary>
/// 初期化
/// </summary>
void TitleUi::Initialize() {
  //画像読み込み
  title_ui_logo_image_ = LoadGraph(kTitleUiImageTitle);
  title_ui_guidance_image_ = LoadGraph(kTitleUiImageGidance);

  //画像の幅と高さを取得
  GetGraphSize(title_ui_logo_image_, &title_logo_width_, &title_logo_height_);
  GetGraphSize(title_ui_guidance_image_, &title_guidance_width_, &title_guidance_height_);

  
  logo_x_ = kLogoX;
  logo_y_ = kLogoY;

  guidance_x_ = kGuidanceX;
  guidance_y_ = kGuidanceY;


}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void TitleUi::Update(float delta_time) {
  // 経過時間を更新
  elapsed_time_ += delta_time; 

  
  // 1秒ごとにガイダンスの表示 / 非表示を切り替える
    if (elapsed_time_ >= kShowGuidance) {
      // フラグを反転させる
      show_guidance_ = !show_guidance_;
      // 経過時間をリセット
      elapsed_time_ = 0.0f;
    }
    if (InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kPlayerFire)) {
      
      FadeManager::GetInstance()->StartLogoFade(kLogoFade);
      FadeManager::GetInstance()->Update(delta_time);
    }
}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void TitleUi::Render() {
  DrawGraph(logo_x_, logo_y_, title_ui_logo_image_, TRUE);

  if (show_guidance_) {
    
    // ガイダンスロゴを拡大して描画
    int expandedGuidanceX = guidance_x_ - (title_guidance_width_ * (zoom_factor_ - kZooMFactor) / kHalf);
    int expandedGuidanceY = guidance_y_ - (title_guidance_height_ * (zoom_factor_ - kZooMFactor) / kHalf);
    int expandedGuidanceWidth = title_guidance_width_ * zoom_factor_;
    int expandedGuidanceHeight = title_guidance_height_ * zoom_factor_;

   
    FadeManager::GetInstance()->FadeOutLogo();

    DrawExtendGraph(expandedGuidanceX, expandedGuidanceY,
      expandedGuidanceX + expandedGuidanceWidth,
      expandedGuidanceY + expandedGuidanceHeight,
      title_ui_guidance_image_, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
  }
}

/// <summary>
/// 破棄
/// </summary>
void TitleUi::DestroyTitleUi() {
  DeleteGraph(title_ui_logo_image_);
  DeleteGraph(title_ui_guidance_image_);
}

/// <summary>
/// ズームするgaidannsu 
/// </summary>
void TitleUi::CheckZoom(){
  zoom_factor_ += kZoom;
    // 経過時間をリセット
  elapsed_time_ = 0.0f;
}


