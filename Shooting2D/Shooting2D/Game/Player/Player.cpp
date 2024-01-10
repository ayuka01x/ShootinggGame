#include "Player.h"
#include "DxLib.h"
#include "System/Input/InputManager.h"
#include "Game/GameInfo/GameInfo.h"
#include "System/Bullet/BulletBase.h"
#include "Game/Item/ItemBase/ItemBase.h"
/// <summary>
/// Player.cppのみで使用する定数
/// </summary>
namespace {

  /// <summary>
  /// プレイヤー画像
  /// </summary>
  const char* kDefoltPlayer = "Assets/Image/Battle/Player/Player.png";

  /// <summary>
  /// 画像の座標
  /// </summary>
  const int kFirstPoint = 600;

  /// <summary>
  /// スピード
  /// </summary>
  const int kSpead = 5;

  /// <summary>
  /// 背景の範囲
  /// </summary>
  const int kXWidthStart = 170;

  /// <summary>
  /// 背景の範囲
  /// </summary>
  const int kXWidthEnd = 1048;

  /// <summary>
  /// 背景の範囲
  /// </summary>
  const int kYWidthStart = -32;

  /// <summary>
  /// 背景の範囲
  /// </summary>
  const int kYWidthEnd = 688;

  /// <summary>
  /// 分割数
  /// </summary>
  const int kPlayerCounts = 3;

  /// <summary>
  /// プレイヤー画像４分割
  /// </summary>
  const int kPlayerSplit = 4;

  /// <summary>
  /// 分割した画像
  /// </summary>
  const int kPlayerImage = 64;

  /// <summary>
  /// 7回に１回弾を発射
  /// </summary>
  const int kBulletRenda = 7;

  /// <summary>
  /// 弾の初期位置
  /// </summary>
  const int kBulletPodition = 16;

  /// <summary>
  /// 弾を出す
  /// </summary>
  const int kBulletFire = 1;

  /// <summary>
  /// 円の衝突
  /// </summary>
  const int kPlayerRadius = 1000;

  const float KspeedUpTime = 3.0f;
}

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
  : player_image_(0)
  , player_x_(0)
  , player_y_(0)
  , player_width_(0)
  , player_height_(0)
  , current_frame_(0)
  , bullet_manager_(nullptr)
  , item_get_(false)
  , item_speed_up_time_(0.0f)
  , player_speed_(0){

}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player() {

}

/// <summary>
/// 初期化
/// </summary>
void Player::Initialize() {
  // 画像を読み込む
  player_image_ = LoadGraph(kDefoltPlayer);

  // 画像の幅と高さを取得
  GetGraphSize(player_image_, &player_width_, &player_height_);

  // 画像を四分割する
  LoadDivGraph(kDefoltPlayer, kPlayerSplit, kHalf, kHalf, kPlayerImage, kPlayerImage, player_images_);

  // 初期位置を設定
  player_x_ = kFirstPoint;
  player_y_ = kFirstPoint;

  player_death_ = false;

  audio_manager_ = new AudioManager();
  audio_manager_->LoadSe();
}

/// <summary>
/// 毎フレームの更新処理 enumにして訂正する
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void Player::Update(float delta_time) {
  PlayerAnimeImageKind current_animation = PlayerAnimeImageKind::kFront;
  if (!player_death_) {

    if (item_get_) {
      player_speed_ = kSpead * KspeedUpTime;
      item_speed_up_time_ += delta_time;
      if (item_speed_up_time_ >= KspeedUpTime) {
        item_speed_up_time_ = 0;
        item_get_ = false;
      }
    }
    else {
      player_speed_ = kSpead;
    }
    //コマンド↑
    if (InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kUp)) {
      player_y_ -= player_speed_;
      current_animation = PlayerAnimeImageKind::kFront;
    }
    //コマンド↓
    if ((InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kDown))) {
      player_y_ += player_speed_;
      current_animation = PlayerAnimeImageKind::kFront;
    }
    //コマンド←
    if (IsAnimationActive(PlayerAnimeImageKind::kLeft)) {
      player_x_ -= player_speed_;
      current_animation = PlayerAnimeImageKind::kLeft;
    }
    //コマンド→
    if (IsAnimationActive(PlayerAnimeImageKind::kRight)) {
      player_x_ += player_speed_;
      current_animation = PlayerAnimeImageKind::kRight;
    }
    //ｚを押したら弾が発射　//if (InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kPlayerFire))
    if (!player_death_) {
      if (InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kPlayerFire)) {
        //10コマに一回出力されるイメージ
        fire_counter_ = (fire_counter_ + kBulletFire) % kBulletRenda;
        if (fire_counter_ == 0) {
          bullet_manager_->FireBullet(BulletManager::BulletKind::kPlayerBullet, player_x_ + kBulletPodition, player_y_ - kBulletRenda);
          audio_manager_->PlaySe(AudioManager::EffectKind::kPlayerBulletShotEffect);
        }
      }
    }


    // 移動範囲の制限
    if (player_x_ < kXWidthStart) player_x_ = kXWidthStart;
    if (player_x_ > kXWidthEnd) player_x_ = kXWidthEnd;
    if (player_y_ < kYWidthStart) player_y_ = kYWidthStart;
    if (player_y_ > kYWidthEnd) player_y_ = kYWidthEnd;

    // 選択したアニメーション状態を使って描画
    current_frame_ = static_cast<int>(current_animation);


    for (EnemyBase* enemy : enemy_manager_->enemy_list_) {
      if (IsCircleCollision(player_x_, player_y_, enemy->GetX(), enemy->GetY()) && enemy->GetEnemyKind() == EnemyManager::EnemyKind::kTackleEnemy) {
        player_death_ = true;
        audio_manager_->PlaySe(AudioManager::EffectKind::kPlayerExplotionEffect);

        effect_manager_->EffectFire(EffectManager::EffectKind::kPlayerEffect, player_x_, player_y_);

      }
    }
    for (BulletBase* bullet : bullet_manager_->bullet_list_) {
      if (IsCircleCollision(player_x_, player_y_, bullet->GetX() - kBulletRenda, bullet->GetY() - kBulletRenda) && bullet->GetBulletKind() == BulletManager::BulletKind::kBossBullet) {
        audio_manager_->PlaySe(AudioManager::EffectKind::kPlayerExplotionEffect);
        effect_manager_->EffectFire(EffectManager::EffectKind::kPlayerEffect, player_x_, player_y_);
        player_death_ = true;
      }
    }
    for (ItemBase* item : item_manager_->item_list_) {
      if (IsCircleCollision(player_x_, player_y_, item->GetX(), item->GetY()) && item->GetItemKind() == ItemManager::ItemKind::kSpeedUp) {
        if (!item->is_item_speed_up_out_of_screen_) {
          audio_manager_->PlaySe(AudioManager::EffectKind::kBossEnemyDamageEffect);
          item->SetItemOutOfScreen(true);
          item_get_ = true;
        }
        
      }
   
    }
  }

}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void Player::Render() {
  if (!player_death_) {
    DrawGraph(player_x_, player_y_, player_images_[current_frame_], TRUE);
  }

}

/// <summary>
/// プレイヤーレベルの管理するものを破棄
/// </summary>
void Player::DestroyPlayer() {
  // プレイヤー画像の解放
  DeleteGraph(player_image_);

  // 画像の分割データの解放
  for (int i = 0; i < kPlayerCounts; ++i) {
    DeleteGraph(player_images_[i]);
  }
  audio_manager_->DeleteBgm();
  delete audio_manager_;
  audio_manager_ = nullptr;

}

/// <summary>
/// Playerの動き
/// </summary>
/// <param name="animation"></param>
/// <returns></returns>
bool Player::IsAnimationActive(Player::PlayerAnimeImageKind animation) {
  if (animation == PlayerAnimeImageKind::kFront) {
    return InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kUp) ||
      InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kDown);
  }
  else if (animation == PlayerAnimeImageKind::kLeft) {
    return InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kLeft);
  }
  else if (animation == PlayerAnimeImageKind::kRight) {
    return InputManager::GetInstance()->IsDown(InputManager::GameKeyKind::kRight);
  }

  return false;
}

/// <summary>
/// BulletManagerのセットアップ
/// </summary>
/// <param name="bullet_manager"></param>
void Player::SetBulletManager(BulletManager* bullet_manager) {
  bullet_manager_ = bullet_manager;
}

/// <summary>
/// 円同士の当たり判定を行う関数
/// </summary>
/// <param name="x1"></param>
/// <param name="y1"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <returns></returns>
bool Player::IsCircleCollision(float player_x, float player_y, float x, float y) {

  float distance_squared = (player_x - x) * (player_x - x) + (player_y - y) * (player_y - y);

  return distance_squared <= kPlayerRadius;
}

/// <summary>
/// EnemyManagerセット
/// </summary>
/// <param name="enemy_manager"></param>
void Player::SetEnemyManager(EnemyManager* enemy_manager) {

  enemy_manager_ = enemy_manager;
}

/// <summary>
/// EffectManagerセット
/// </summary>
/// <param name="effect_manager"></param>
void Player::SetEffectManager(EffectManager* effect_manager) {

  effect_manager_ = effect_manager;
}

/// <summary>
/// ItemManagerセット
/// </summary>
/// <param name="item_manager"></param>
void Player::SetItemManager(ItemManager* item_manager) {

  item_manager_ = item_manager;
}



