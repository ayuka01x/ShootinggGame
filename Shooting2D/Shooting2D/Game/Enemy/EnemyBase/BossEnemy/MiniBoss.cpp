#include "MiniBoss.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// ボス画像
  /// </summary>
  const char* kBossEnemyImage = "Assets/Image/Battle/Enemy/BossEnemy.png";

  /// <summary>
  /// 速度
  /// </summary>
  const float kLeft = 100.0f;

  /// <summary>
  /// 速度
  /// </summary>
  const float kRight = -100.0f;

  /// <summary>
  /// 右側の限界
  /// </summary>
  const int kRightDistance = 900;

  /// <summary>
  /// 点滅
  /// </summary>
  const float kBossBright = 0.1f;

  /// <summary>
  /// 光
  /// </summary>
  const int kBright = 100;

  /// <summary>
  /// 距離調整
  /// </summary>
  const float kDistance = 50.0f;

  /// <summary>
  /// 距離
  /// </summary>
  const int kDistanceX = 100;

  /// <summary>
  /// 端の場所
  /// </summary>
  const int kLeftDistance = 200;

  /// <summary>
  /// 色の上限
  /// </summary>
  const int kColorMax = 255;

  /// <summary>
  /// 2倍の速度
  /// </summary>
  const int kDoubleSpeed = 2;
}
/// <summary>
/// コンストラクタ
/// </summary>
MiniBossEnemy::MiniBossEnemy()
  : miniboss_enemy_x_(0)
  , miniboss_enemy_y_(0)
  , miniboss_enemy_speed_(0.0f)
  , miniboss_enemy_image_(0)
  , miniboss_enemy_width_(0)
  , miniboss_enemy_height_(0)
  , is_miniboss_enemy_out_of_screen_(false)
  , elapsed_time_(0)
  , miniboss_time_(0) {

}

/// <summary>
/// デストラクタ
/// </summary>
MiniBossEnemy::~MiniBossEnemy() {

}

/// <summary>
/// 敵の更新処理
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
void MiniBossEnemy::Initialize(float x, float y, float speed, float time) {
  miniboss_enemy_x_ = x;
  miniboss_enemy_y_ = y;
  miniboss_enemy_speed_ = speed;
  miniboss_time_ = time;

  if (miniboss_enemy_image_ != 0) {
    DeleteGraph(miniboss_enemy_image_);
  }

  //画像を読み込み,高さ幅を取得
  miniboss_enemy_image_ = LoadGraph(kBossEnemyImage);
  GetGraphSize(miniboss_enemy_image_, &miniboss_enemy_width_, &miniboss_enemy_height_);

  is_enemy_fired_ = false;
  is_miniboss_enemy_out_of_screen_ = true;
  is_bullet_hit_ = true;
  miniboss_death_ = false;
}

/// <summary>
/// 敵の描画処理
/// </summary>
/// <param name="delta_time"></param>
void MiniBossEnemy::Update(float delta_time) {
  if (IsEnemyFired() && !miniboss_death_) {
    if (miniboss_enemy_y_ <= kBright) {
      miniboss_enemy_speed_y_ = kBright;
    }
    if (miniboss_enemy_y_ >= kLeftDistance) {
      miniboss_enemy_speed_y_ = -kBright;
    }

    // もしボスが左まで行ったら右に移動するようにする
    if (miniboss_enemy_x_ >= kRightDistance) {
      miniboss_enemy_speed_ = kRight;

    }
    // もしボスが右まで行ったら左に移動するようにする
    else if (miniboss_enemy_x_ <= kLeftDistance) {
      miniboss_enemy_speed_ = kLeft;

    }

    miniboss_enemy_y_ += miniboss_enemy_speed_y_ * delta_time;
    miniboss_enemy_x_ += miniboss_enemy_speed_ * delta_time * kDoubleSpeed;
  }
  if (!is_bullet_hit_) {
    elapsed_time_ += delta_time;
    if (elapsed_time_ >= kBossBright) {
      is_bullet_hit_ = true;
      elapsed_time_ = 0;
    }
  }
}



/// <summary>
/// /描画
/// </summary>
void MiniBossEnemy::Render() {
  //描画
  if (!is_miniboss_enemy_out_of_screen_ && !miniboss_death_) {

    if (!is_bullet_hit_) {

      SetDrawBlendMode(DX_BLENDMODE_ADD, kBright);
    }
    SetDrawBright(0, 0, kColorMax);
    DrawGraph(miniboss_enemy_x_, miniboss_enemy_y_, miniboss_enemy_image_, TRUE);
    SetDrawBright(kColorMax, kColorMax, kColorMax);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
  }

}

/// <summary>
/// 敵の種類取得
/// </summary>
/// <returns></returns>
EnemyManager::EnemyKind MiniBossEnemy::GetEnemyKind() {

  return EnemyManager::EnemyKind::kMiniBossEnemy;
};

/// <summary>
/// 動き
/// </summary>
/// <param name="tackle_enemy_x"></param>
/// <param name="tackle_enemy_y"></param>
void MiniBossEnemy::FireEnemy(float tackle_enemy_x, float tackle_enemy_y) {
  if (!miniboss_death_) {

    miniboss_enemy_x_ = tackle_enemy_x;
    miniboss_enemy_y_ = tackle_enemy_y;
    is_enemy_fired_ = true;
    is_miniboss_enemy_out_of_screen_ = false;

  }

}

/// <summary>
/// 外に出たか設定
/// </summary>
/// <param name="is_tackle_enemy_out_of_screen"></param>
void MiniBossEnemy::SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen) {

  is_miniboss_enemy_out_of_screen_ = is_tackle_enemy_out_of_screen;
}

/// <summary>
/// 発射されたかどうかを設定
/// </summary>
/// <param name="is_enemy_fired"></param>
void MiniBossEnemy::SetEnemyFire(bool is_enemy_fired) {

  is_enemy_fired_ = is_enemy_fired;
}

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float MiniBossEnemy::GetX() {

  return miniboss_enemy_x_;
}

/// <summary>
/// ｙ座標取得
/// </summary>
/// <returns></returns>
float MiniBossEnemy::GetY() {

  return miniboss_enemy_y_;
}

/// <summary>
/// 横幅
/// </summary>
/// <returns></returns>
float MiniBossEnemy::GetWidth() {

  return miniboss_enemy_width_;
}

/// <summary>
/// 弾があたったかどうか
/// </summary>
/// <param name="is_bullet_hit"></param>
void MiniBossEnemy::SetBulletHit(bool is_bullet_hit) {

  is_bullet_hit_ = is_bullet_hit;

}

/// <summary>
/// 出現時間取得
/// </summary>
/// <returns></returns>
float MiniBossEnemy::GetTime() {
  return miniboss_time_;
}

/// <summary>
/// ミニボスが死んだかどうか
/// </summary>
/// <param name="miniboss_death"></param>
void MiniBossEnemy::SetMiniBossDeath(bool miniboss_death) {
  miniboss_death_ = miniboss_death;
}