#include "BossBullet.h"
#include "DxLib.h"

/// <summary>
/// コンストラクタ
/// </summary>
BossBullet::BossBullet()
  : boss_bullet_x_(0.0f)
  , boss_bullet_y_(0.0f)
  , boss_bullet_speed_(0.0f)
  , boss_bullet_image_(0)
  , boss_bullet_width_(0)
  , boss_bullet_height_(0)
  , boss_is_out_of_screen_(false) {
}

/// <summary>
/// デストラクタ
/// </summary>
BossBullet::~BossBullet() {

}

/// <summary>
/// 敵の初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
void BossBullet::Initialize(float x, float y, float speed) {
  boss_bullet_x_ = x;
  boss_bullet_y_ = y;
  boss_bullet_speed_ = speed;

  if (boss_bullet_image_ != 0) {
    DeleteGraph(boss_bullet_image_);
  }

  //画像を読み込み,高さ幅を取得
  boss_bullet_image_ = LoadGraph("Assets/Image/Battle/Bullet/BossEnemyBullet.png");
  GetGraphSize(boss_bullet_image_, &boss_bullet_width_, &boss_bullet_height_);

  boss_is_out_of_screen_ = false;
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="delta_time"></param>
void BossBullet::Update(float delta_time) {
  boss_bullet_speed_ = 500.0f;
  if (!boss_is_out_of_screen_) {

    // 下に向かって移動
    boss_bullet_y_ += boss_bullet_speed_ * delta_time;

    if (boss_bullet_y_ + boss_bullet_height_ > 720) {
      // 画面外に出たら発射済みフラグをOFFにする
      boss_is_out_of_screen_ = true;
      is_fired_ = false;
    }
  }
}

/// <summary>
/// 描画
/// </summary>
void BossBullet::Render() {

  if (!boss_is_out_of_screen_) {
    DrawGraph(boss_bullet_x_, boss_bullet_y_, boss_bullet_image_, TRUE);
  }
}

/// <summary>
/// 弾の種類
/// </summary>
/// <returns></returns>
BulletManager::BulletKind BossBullet::GetBulletKind() {

  return BulletManager::BulletKind::kBossBullet;
}

/// <summary>
/// 弾の発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BossBullet::FireBullet(float x, float y) {
  boss_bullet_x_ = x;
  boss_bullet_y_ = y;
  boss_is_out_of_screen_ = false;
  is_fired_ = true;
}

/// <summary>
/// 弾が画面外に出たかどうかを判定
/// </summary>
/// <returns></returns>
bool BossBullet::IsOutOfScreen() {
  return boss_is_out_of_screen_;
}

/// <summary>
/// ｘ座標取得
/// </summary>
/// <returns></returns>
float BossBullet::GetX() {

  return boss_bullet_x_;
}

/// <summary>
/// y座標取得
/// </summary>
/// <returns></returns>
float BossBullet::GetY() {

  return boss_bullet_y_;
}

/// <summary>
/// 弾が発射されたかどうかを設定
/// </summary>
/// <param name="fired"></param>
void BossBullet::SetFired(bool fired) {
  is_fired_ = fired;
}

/// <summary>
/// 外に出たかどうか設定
/// </summary>
/// <param name="out_of_screen"></param>
void BossBullet::SetIsOutOfScreen(bool out_of_screen) {
  boss_is_out_of_screen_ = out_of_screen;
}

/// <summary>
/// 弾の座標を設定する関数
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BossBullet::SetPosition(float x, float y) {
  boss_bullet_x_ = x;
  boss_bullet_y_ = y;
}
