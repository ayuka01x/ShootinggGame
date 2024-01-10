#include "BossEnemy.h"
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
  const int kDistanceX = 50;

  /// <summary>
  /// 端の場所
  /// </summary>
  const int kLeftDistance = 200;
}
/// <summary>
/// コンストラクタ
/// </summary>
BossEnemy::BossEnemy()
  : boss_enemy_x_(0)
  , boss_enemy_y_(0)
  , boss_enemy_speed_(0.0f)
  , boss_enemy_image_(0)
  , boss_enemy_width_(0)
  , boss_enemy_height_(0)
  , is_boss_enemy_out_of_screen_(false)
  , elapsed_time_(0)
  , boss_time_(0) {

}

/// <summary>
/// デストラクタ
/// </summary>
BossEnemy::~BossEnemy() {

}

/// <summary>
/// 敵の更新処理
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
void BossEnemy::Initialize(float x, float y, float speed, float time) {
  boss_enemy_x_ = x;
  boss_enemy_y_ = y;
  boss_enemy_speed_ = speed;
  boss_time_ = time;
  if (boss_enemy_image_ != 0) {
    DeleteGraph(boss_enemy_image_);
  }

  //画像を読み込み,高さ幅を取得
  boss_enemy_image_ = LoadGraph(kBossEnemyImage);
  GetGraphSize(boss_enemy_image_, &boss_enemy_width_, &boss_enemy_height_);

  is_enemy_fired_ = false;
  is_boss_enemy_out_of_screen_ = true;
  is_bullet_hit_ = true;
  boss_death_ = false;
}

/// <summary>
/// 敵の描画処理
/// </summary>
/// <param name="delta_time"></param>
void BossEnemy::Update(float delta_time) {
  if (IsEnemyFired()) {
    if (boss_enemy_y_ <= kDistanceX) {
      boss_enemy_y_ += boss_enemy_speed_ * delta_time;
    }
    if (boss_enemy_y_ >= kDistanceX) {
      // もしボスが左まで行ったら右に移動するようにする
      if (boss_enemy_x_ >= kRightDistance) {
        boss_enemy_speed_ = kRight;

      }
      // もしボスが右まで行ったら左に移動するようにする
      else if (boss_enemy_x_ <= kLeftDistance) {
        boss_enemy_speed_ = kLeft;

      }


      boss_enemy_x_ += boss_enemy_speed_ * delta_time;
    }
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
void BossEnemy::Render() {
  //描画
  if (!is_boss_enemy_out_of_screen_) {

    if (!is_bullet_hit_) {

      SetDrawBlendMode(DX_BLENDMODE_ADD, kBright);

    }

    DrawGraph(boss_enemy_x_, boss_enemy_y_, boss_enemy_image_, TRUE);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

  }

}

/// <summary>
/// 敵の種類取得
/// </summary>
/// <returns></returns>
EnemyManager::EnemyKind BossEnemy::GetEnemyKind() {
  return EnemyManager::EnemyKind::kBossEnemy;
}

/// <summary>
/// 動き
/// </summary>
/// <param name="tackle_enemy_x"></param>
/// <param name="tackle_enemy_y"></param>
void BossEnemy::FireEnemy(float tackle_enemy_x, float tackle_enemy_y) {
  if (!boss_death_) {
    boss_enemy_x_ = tackle_enemy_x;
    boss_enemy_y_ = tackle_enemy_y;
    is_enemy_fired_ = true;
    is_boss_enemy_out_of_screen_ = false;
  }

}

/// <summary>
/// 外に出たか設定
/// </summary>
/// <param name="is_tackle_enemy_out_of_screen"></param>
void BossEnemy::SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen) {
  is_boss_enemy_out_of_screen_ = is_tackle_enemy_out_of_screen;
}

/// <summary>
/// 発射されたかどうかを設定
/// </summary>
/// <param name="is_enemy_fired"></param>
void BossEnemy::SetEnemyFire(bool is_enemy_fired) {
  is_enemy_fired_ = is_enemy_fired;
}

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float BossEnemy::GetX() {
  return boss_enemy_x_;
}

/// <summary>
/// ｙ座標取得
/// </summary>
/// <returns></returns>
float BossEnemy::GetY() {
  return boss_enemy_y_;
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <returns></returns>
float BossEnemy::GetWidth() {
  return boss_enemy_width_;
}

/// <summary>
/// 弾があたったかどうか
/// </summary>
/// <param name="is_bullet_hit"></param>
void BossEnemy::SetBulletHit(bool is_bullet_hit) {

  is_bullet_hit_ = is_bullet_hit;
}

/// <summary>
/// 出現時間取得
/// </summary>
/// <returns></returns>
float BossEnemy::GetTime() {
  return boss_time_;
}

/// <summary>
/// ボス死亡判定
/// </summary>
/// <param name="boss_death"></param>
void BossEnemy::SetBossDeath(bool boss_death) {
  boss_death_ = boss_death;
}

