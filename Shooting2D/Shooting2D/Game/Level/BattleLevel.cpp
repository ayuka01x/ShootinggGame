#include "DxLib.h"
#include "Game/Level/BattleLevel.h"
#include "Game/Level/LevelChanger.h"
#include "System/Input/InputManager.h"
#include <Game/Enemy/EnemyBase/BossEnemy/BossEnemy.h>
#include <random>

/// <summary>
/// BattleLevel.cppのみで使用する定数
/// </summary>
namespace {

  /// <summary>
  /// 背景画像
  /// </summary>
  const char* kBattleBgImageFilePath = "Assets/Image/Battle/Background/BaseBgSky01.png";

  /// <summary>
  /// 背景画像
  /// </summary>
  const char* kBattleImageScrollOne = "Assets/Image/Battle/Background/ScrollBgSky01.png";

  /// <summary>
  /// 背景画像
  /// </summary>
  const char* kBattleBgImageScrollTwo = "Assets/Image/Battle/Background/ScrollBgSky02.png";

  /// <summary>
  /// 背景画像
  /// </summary>
  const char* kBattleBgImageScrollThree = "Assets/Image/Battle/Background/ScrollBgSky03.png";

  /// <summary>
  /// 背景画像のX座標
  /// </summary>
  const int kBgPosX = 200;

  /// <summary>
  /// レベルの切り替え時間
  /// </summary>
  const float kChangeLevelTime = 15.0f;

  /// <summary>
  /// 表示時間
  /// </summary>
  const float kScrollSpeeds[] = { 450.0f, 700.0f, 900.0f };

  /// <summary>
  /// ScrollBgSky02.png
  /// </summary>
  const int kImageScrollTwo = 1;

  /// <summary>
  /// ScrollBgSky03.png
  /// </summary>
  const int kImageScrollThree = 2;

  /// <summary>
  /// スクロールされる画像
  /// </summary>
  const int kScroll = 3;

  /// <summary>
  /// フェードイン時間
  /// </summary>
  const float kFadeIn = 0.5f;

  /// <summary>
  /// フェードアウト時間
  /// </summary>
  const float kFadeOutTime = 1.5f;

  /// <summary>
  /// 最初の敵の初期X位置
  /// </summary>
  const float kStartX = 200.0f;

  /// <summary>
  /// 最初の敵の初期Y位置
  /// </summary>
  const float kStartY = 0.0f;

  /// <summary>
  /// 弾とのずれ間の横のスペース
  /// </summary>
  const float kSpacingX = 50.0f;

  /// <summary>
  /// 敵の位置終わり
  /// </summary>
  const float kFinishX = 1000.0f;

  /// <summary>
  /// 敵の横列
  /// </summary>
  const int kEnemyX = 14;

  /// <summary>
  /// 敵出現する時間
  /// </summary>
  const float kEnemyFire = 2.7f;

  /// <summary>
  /// ボス出現
  /// </summary>
  const float kBossFire = 8.0f;

  /// <summary>
  /// ボスの位置
  /// </summary>
  const float kBossEnemyX = 600.0f;

  /// <summary>
  /// 弾の位置
  /// </summary>
  const float kBossBulletY = 70.0f;

  /// <summary>
  /// 弾打つ頻度
  /// </summary>
  const int kBossRender = 40;

  /// <summary>
  /// ボスの位置
  /// </summary>
  const int kBossDictance = 530;

  /// <summary>
  /// 切り替えの時間
  /// </summary>
  const float kChangetime = 5.0f;

  /// <summary>
  /// クリア時の音の時間
  /// </summary>
  const float kBattleCleartime = 3.5f;

  /// <summary>
  /// ランダム範囲
  /// </summary>
  const int kRandomRange = 900;

  /// <summary>
  /// アイテム初期位置
  /// </summary>
  const float kSpeedUpY = -100;
}


/// <summary>
/// コンストラクタ
/// </summary>
BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone)
  , battle_bg_handle_(0)
  , elapsed_time_(0.0f)
  , player_(nullptr)
  , bullet_manager_(nullptr)
  , fade_out_(false)
  , battle_ui_fire_(false)
  , item_time_(0.0f){

}

/// <summary>
/// デストラクタ
/// </summary>
BattleLevel::~BattleLevel() {

}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void BattleLevel::Update(float delta_time) {
  elapsed_time_ += delta_time;
  //何もしない状態なら実行しない
  if (battle_level_state_ == BattleLevelState::kNone) {
    return;
  }
  //フェードイン
  if (!fade_out_) {
    FadeManager::GetInstance()->StartFadeIn(kFadeIn);
    FadeManager::GetInstance()->Update(delta_time);

  }

  
  
  //敵発射

  TackleEnemyBattle();

  MiniBossBattle();

  

  if (bullet_manager_->miniboss_dead_) {
    boss_battle_time_ += elapsed_time_;
    if (boss_battle_time_ >= kFadeOutTime) {
      BossBattle();
    }
    
  }
  item_time_ += delta_time;

  ItemFire();

  if (bullet_manager_->boss_dead_ || player_->player_death_) {
    if (!fade_out_) {

      FadeManager::GetInstance()->StartFadeOut(kFadeOutTime);
      fade_out_ = true;

    }
    if (finish_elapsed_time_ >= kBattleCleartime) {
      if (!battle_ui_fire_) {
        if (!player_->player_death_) {
          audio_manager_->PlaySe(AudioManager::EffectKind::kBattleClearEffect);
        }

        battle_ui_fire_ = true;
      }
      FadeManager::GetInstance()->Update(delta_time);

    }

  }

  if (bullet_manager_->boss_dead_ || player_->player_death_) {

    finish_elapsed_time_ += delta_time;

    if (finish_elapsed_time_ >= kChangetime) {

      //状態を何もしないへ
      battle_level_state_ = BattleLevelState::kNone;

      //レベルチェンジャーの状態をタイトルレベル終了へ
      /* ココはレベルチェンジャー実装後に自分で記述する */
      LevelChanger::GetInstance()->SetLevelChangerState(LevelChanger::LevelChangerState::kFinBattleLevel);
    }

  }
  if (player_->player_death_) {
    audio_manager_->FadeOutBgm(kFadeOutTime);
  }
  if (bullet_manager_->boss_dead_) {
    audio_manager_->StopBgm();
  }
}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void BattleLevel::Render() {
  //バトル背景
  DrawGraph(kBgPosX, 0, battle_bg_handle_, TRUE);
  //サイド
  side_ui_->Render();

  for (int i = 0; i < kScroll; ++i) {
    int bg_handle = battle_scroll_handles_[i];
    float scroll_speed = kScrollSpeeds[i];

    if (bg_handle != 0) {
      int bg_width, bg_height;
      GetGraphSize(bg_handle, &bg_width, &bg_height);

      //経過時間*背景スクロール速度＝スクロールされている位置
      int scroll_pos = static_cast<int>(elapsed_time_ * scroll_speed);

      //背景の画面外から描写して背景ループさせる（エンドレスところてんみたいなイメージ）
      int draw_y_one = -bg_height + scroll_pos % bg_height;
      //途切れさせないようにする１枚目の位置+背景の高さで一枚目の下にくっつける。
      int draw_y_two = draw_y_one + bg_height;

      //２つを描写
      DrawGraph(kBgPosX, draw_y_one, bg_handle, TRUE);
      DrawGraph(kBgPosX, draw_y_two, bg_handle, TRUE);
    }
  }
  if (bullet_manager_->boss_dead_) {
    battle_ui_->SetGameClear(true);


  }
  if (player_->player_death_) {
    battle_ui_->SetGameOver(true);

  }
}

/// <summary>
/// レベルの開始処理
/// </summary>
void BattleLevel::BeginLevel() {

  //背景読み込み
  battle_bg_handle_ = LoadGraph(kBattleBgImageFilePath);

  //3枚のスクロール背景画像を読み込む
  battle_scroll_handles_[0] = LoadGraph(kBattleImageScrollOne);
  battle_scroll_handles_[kImageScrollTwo] = LoadGraph(kBattleBgImageScrollTwo);
  battle_scroll_handles_[kImageScrollThree] = LoadGraph(kBattleBgImageScrollThree);

  //状態を通常へ
  battle_level_state_ = BattleLevelState::kPlay;

  //Playerクラスのインスタンスを生成
  player_ = new Player();

  //BattleUiクラスのインスタンスを生成
  battle_ui_ = new BattleUi();

  //sideuiクラスのインスタンス生成
  side_ui_ = new SideUi();

  //BulletManagerのインスタンス
  bullet_manager_ = new BulletManager();

  //EnemyManagerのインスタンス
  enemy_manager_ = new EnemyManager();

  //EffectManagerのインスタンス
  effect_manager_ = new EffectManager();

  audio_manager_ = new AudioManager();

  item_manager_ = new ItemManager();

  //Playerクラスの初期化
  player_->Initialize();

  //BattleUiクラスの初期化
  battle_ui_->Initialize();

  //sideuiクラスの初期化
  side_ui_->Initialize();

  //BulletManagerの初期化
  bullet_manager_->Initialize();

  //EnemyManagerの初期化
  enemy_manager_->Initialize();

  effect_manager_->Initialize();

  audio_manager_->LoadBgm();
  audio_manager_->PlayBgm(AudioManager::BgmKind::kBattleBgm);
  audio_manager_->LoadSe();

  item_manager_->Initialize();

  //プレイヤーにバレットマネージャーを入れる
  player_->SetBulletManager(bullet_manager_);

  //プレイヤーをタスクに登録
  TaskManager::GetInstance()->AddTask(player_);

  //バレットをタスクに登録
  TaskManager::GetInstance()->AddTask(bullet_manager_);

  //EnemyManagerをタスクに登録
  TaskManager::GetInstance()->AddTask(enemy_manager_);

  TaskManager::GetInstance()->AddTask(effect_manager_);

  TaskManager::GetInstance()->AddTask(battle_ui_);

  TaskManager::GetInstance()->AddTask(item_manager_);

  //enemymanagerをセットする関数を作ってバレットマネージャーにいれる
  bullet_manager_->SetEnemyManager(enemy_manager_);
  bullet_manager_->SetEffecManager(effect_manager_);
  player_->SetEnemyManager(enemy_manager_);
  player_->SetEffectManager(effect_manager_);
  player_->SetItemManager(item_manager_);
}

/// <summary>
/// バトルレベルの管理するものをタスクマネージャーから解放する
/// </summary>
void BattleLevel::ReleaseLevel() {
  TaskManager::GetInstance()->ReleaseTask(player_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(bullet_manager_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(battle_ui_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(side_ui_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(enemy_manager_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(effect_manager_->GetTaskId());
  TaskManager::GetInstance()->ReleaseTask(item_manager_->GetTaskId());
}

/// <summary>
/// バトルレベルの管理するものを破棄
/// </summary>
void BattleLevel::DestroyLevel() {

  //背景画像破棄
  DeleteGraph(battle_bg_handle_);

  // bg_handle_one解放
  int bg_handle_one = LoadGraph(kBattleImageScrollOne);
  if (bg_handle_one != 0) {
    DeleteGraph(bg_handle_one);
  }
  // bg_handle_two解放
  int bg_handle_two = LoadGraph(kBattleImageScrollOne);
  if (bg_handle_two != 0) {
    DeleteGraph(bg_handle_two);
  }

  //プレイヤークラスの破棄
  player_->DestroyPlayer();
  delete player_;
  player_ = nullptr;

  //バレットマネージャークラスの破棄
  bullet_manager_->DestroyBullet();
  delete bullet_manager_;
  bullet_manager_ = nullptr;

  //バトルUIクラスの破棄
  battle_ui_->DestroyBatttlUi();
  delete battle_ui_;
  battle_ui_ = nullptr;

  //サイドUIクラスの破棄
  side_ui_->DestroySideUi();
  delete side_ui_;
  side_ui_ = nullptr;

  enemy_manager_->DestroyEnemy();
  delete enemy_manager_;
  enemy_manager_ = nullptr;

  effect_manager_->DestroyEffect();
  delete effect_manager_;
  effect_manager_ = nullptr;

  audio_manager_->DeleteBgm();
  audio_manager_->DeleteSe();
  delete audio_manager_;
  audio_manager_ = nullptr;

  item_manager_->DestroyItem();
  delete item_manager_;
  item_manager_ = nullptr;
}

/// <summary>
/// ボスバトル
/// </summary>
void BattleLevel::BossBattle() {
 
  enemy_manager_->EnemyFire(EnemyManager::EnemyKind::kBossEnemy);

  
  float boss_x = enemy_manager_->GetBossX();
  if (boss_x != kBossDictance) {
    if (elapsed_time_ >= kBossFire) {
      boss_count_ = (boss_count_ + kImageScrollTwo) % kBossRender;
    }
    if (boss_count_ == 0) {
      bullet_manager_->FireBullet(BulletManager::BulletKind::kBossBullet, boss_x + kSpacingX, kBossBulletY);
      if (!bullet_manager_->boss_dead_) {
        audio_manager_->PlaySe(AudioManager::EffectKind::kBossBulletShotEffect);
      }
    }
  }
}

/// <summary>
/// タックルエネミーバトル
/// </summary>
void BattleLevel::TackleEnemyBattle() {
  for (int i = 0; i < kEnemyX; ++i) {
    if (!bullet_manager_->boss_dead_) {
      enemy_manager_->EnemyFire(EnemyManager::EnemyKind::kTackleEnemy);
    }

  }

}

/// <summary>
/// ミニボスバトル
/// </summary>
void BattleLevel::MiniBossBattle(){
  enemy_manager_->EnemyFire(EnemyManager::EnemyKind::kMiniBossEnemy);
}

/// <summary>
/// アイテム発射
/// </summary>
void BattleLevel::ItemFire() {

  if (item_time_ >= kChangeLevelTime) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int min_x_ = kBgPosX;
    int max_x_ = kRandomRange;
    std::uniform_int_distribution<int> distrib(min_x_, max_x_);
    item_x_ = distrib(gen);
    item_manager_->ItemFire(ItemManager::ItemKind::kSpeedUp, item_x_, kSpeedUpY);
    item_time_ = 0;
  }
  
}


