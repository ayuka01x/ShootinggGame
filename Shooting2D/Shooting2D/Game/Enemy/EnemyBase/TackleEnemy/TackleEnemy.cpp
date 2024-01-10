#include "TackleEnemy.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// 敵の速さ
  /// </summary>
  const float kTaskleSpeed = 200.0f;

  /// <summary>
  /// タックルエネミー
  /// </summary>
  const char* kTackleEnemyImage = "Assets/Image/Battle/Enemy/TackleEnemy.png";

  /// <summary>
  /// 縦の長さ
  /// </summary>
  const int kTackleEnemayMax = 720;
}
/// <summary>
/// コンストラクタ
/// </summary>
TackleEnemy::TackleEnemy()
  : tackle_enemy_x_(0)
  , tackle_enemy_y_(0)
  , tackle_enemy_speed_(0.0f)
  , tackle_enemy_image_(0)
  , tackle_enemy_width_(0)
  , tackle_enemy_height_(0)
  , is_tackle_enemy_out_of_screen_(false)
  , tackle_time_(0) {

}

/// <summary>
/// デストラクタ
/// </summary>
TackleEnemy::~TackleEnemy() {

}

/// <summary>
/// 敵の更新処理
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
/// <param name="image_path"></param>
void TackleEnemy::Initialize(float x, float y, float speed, float time) {
  tackle_enemy_x_ = x;
  tackle_enemy_y_ = y;
  tackle_enemy_speed_ = speed;
  tackle_time_ = time;
  if (tackle_enemy_image_ != 0) {
    DeleteGraph(tackle_enemy_image_);
  }

  //画像を読み込み,高さ幅を取得
  tackle_enemy_image_ = LoadGraph(kTackleEnemyImage);
  GetGraphSize(tackle_enemy_image_, &tackle_enemy_width_, &tackle_enemy_height_);

  is_tackle_enemy_out_of_screen_ = false;
  is_enemy_fired_ = false;
}

/// <summary>
/// 敵の描画処理
/// </summary>
/// <param name="delta_time"></param>
void TackleEnemy::Update(float delta_time) {

  if (IsEnemyFired()) {
    tackle_enemy_y_ += tackle_enemy_speed_ * delta_time;

    // エネミーが画面外に出たかどうかをチェック
    if (tackle_enemy_y_ >= kTackleEnemayMax) {
      is_tackle_enemy_out_of_screen_ = true;


    }
  }

}

/// <summary>
/// 描画
/// </summary>
void TackleEnemy::Render() {

  if (IsEnemyFired()) {
    DrawGraph(tackle_enemy_x_, tackle_enemy_y_, tackle_enemy_image_, TRUE); 
  }
}

/// <summary>
/// 敵の種類取得
/// </summary>
/// <returns></returns>
EnemyManager::EnemyKind TackleEnemy::GetEnemyKind() {

  return EnemyManager::EnemyKind::kTackleEnemy;
}

/// <summary>
///  弾が画面外に出たかどうかを判定
/// </summary>
/// </summary>
/// <returns></returns>
bool TackleEnemy::IsEnemyOutOfScreen() {
  return is_tackle_enemy_out_of_screen_;
}

/// <summary>
/// 動き
/// </summary>
/// <param name="tackle_enemy_x"></param>
/// <param name="tackle_enemy_y"></param>
void TackleEnemy::FireEnemy(float tackle_enemy_x, float tackle_enemy_y) {
  tackle_enemy_x_ = tackle_enemy_x;
  tackle_enemy_y_ = tackle_enemy_y;
  is_tackle_enemy_out_of_screen_ = false;
  is_enemy_fired_ = true;

}

/// <summary>
/// 外に出たか設定
/// </summary>
/// <param name="is_tackle_enemy_out_of_screen"></param>
void TackleEnemy::SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen) {
  is_tackle_enemy_out_of_screen_ = is_tackle_enemy_out_of_screen;
}

/// <summary>
/// 発射されたかどうかを設定
/// </summary>
/// <param name="is_enemy_fired"></param>
void TackleEnemy::SetEnemyFire(bool is_enemy_fired) {
  is_enemy_fired_ = is_enemy_fired;
  tackle_enemy_y_ = kTackleEnemayMax;
}

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float TackleEnemy::GetX() {
  return tackle_enemy_x_;
}

/// <summary>
/// y座標取得
/// </summary>
/// <returns></returns>
float TackleEnemy::GetY() {
  return tackle_enemy_y_;
}

/// <summary>
/// 弾があたったかどうか
/// </summary>
/// <param name="is_bullet_hit"></param>
void TackleEnemy::SetBulletHit(bool is_bullet_hit) {
  is_bullet_hit_ = is_bullet_hit;
}

/// <summary>
/// 取得時間
/// </summary>
/// <returns></returns>
float TackleEnemy::GetTime() {
  return tackle_time_;
}

