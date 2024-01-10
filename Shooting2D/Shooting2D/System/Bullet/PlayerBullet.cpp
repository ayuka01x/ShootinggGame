#include "PlayerBullet.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// 速さ
  /// </summary>
  const float kSpeed = 500.0f;
}
/// <summary>
/// コンストラクタ
/// </summary>
PlayerBullet::PlayerBullet()
  : bullet_x_(0.0f)
  , bullet_y_(0.0f)
  , bullet_speed_(0.0f)
  , bullet_image_(0)
  , bullet_width_(0)
  , bullet_height_(0)
  , is_out_of_screen_(false) {

}

/// <summary>
/// デストラクタ
/// </summary>
PlayerBullet::~PlayerBullet() {
  DeleteGraph(bullet_image_);
}

/// <summary>
/// プレイヤー弾の初期化関数
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
/// <param name="image_path"></param>
void PlayerBullet::Initialize(float x, float y, float speed) {
  bullet_x_ = x;
  bullet_y_ = y;
  bullet_speed_ = speed;

  if (bullet_image_ != 0) {
    DeleteGraph(bullet_image_);
  }

  //画像を読み込み,高さ幅を取得
  bullet_image_ = LoadGraph("Assets/Image/Battle/Bullet/PlayerBullet.png");
  GetGraphSize(bullet_image_, &bullet_width_, &bullet_height_);

  is_out_of_screen_ = false;
}


/// <summary>
/// 更新処理
/// </summary>
/// <param name="delta_time"></param>
void PlayerBullet::Update(float delta_time) {
  bullet_speed_ = kSpeed;
  if (!is_out_of_screen_) {

    // 上に向かって移動
    bullet_y_ -= bullet_speed_ * delta_time;

    if (bullet_y_ + bullet_height_ < 0) {
      // 画面外に出たら発射済みフラグをOFFにする
      is_out_of_screen_ = true;
      is_fired_ = false;
    }
  }

}

/// <summary>
/// 描画
/// </summary>
void PlayerBullet::Render() {
  if (!is_out_of_screen_) {
    DrawGraph(bullet_x_, bullet_y_, bullet_image_, TRUE);
  }
}

/// <summary>
/// 弾の種類
/// </summary>
/// <returns></returns>
BulletManager::BulletKind PlayerBullet::GetBulletKind() {

  return BulletManager::BulletKind::kPlayerBullet;
}

/// <summary>
/// 弾の発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void PlayerBullet::FireBullet(float x, float y) {

  bullet_x_ = x;
  bullet_y_ = y;
  is_out_of_screen_ = false;
  is_fired_ = true;

}

/// <summary>
/// 弾が画面外に出たかどうかを判定
/// </summary>
/// </summary>
/// <returns></returns>
bool PlayerBullet::IsOutOfScreen() {

  return is_out_of_screen_;
}
//画面外に出た処理参考に弾があった時に消すのisfiredをfalseみたいにやる

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float PlayerBullet::GetX() {
  return bullet_x_;
}

/// <summary>
/// y座標取得
/// </summary>
/// <returns></returns>
float PlayerBullet::GetY() {
  return bullet_y_;
}

/// <summary>
/// 横幅取得
/// </summary>
/// <returns></returns>
float PlayerBullet::GetWidth() {
  return bullet_width_;
}

/// <summary>
/// 弾が発射されたかどうかを設定
/// </summary>
/// <param name="fired"></param>
void PlayerBullet::SetFired(bool fired) {
  is_fired_ = fired;
}

/// <summary>
/// 外に出たかどうか設定
/// </summary>
/// <param name="out_of_screen"></param>
void PlayerBullet::SetIsOutOfScreen(bool out_of_screen) {
  is_out_of_screen_ = out_of_screen;
}

/// <summary>
/// 弾の座標を設定する関数
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void PlayerBullet::SetPosition(float x, float y) {
  bullet_x_ = x;
  bullet_y_ = y;
}




