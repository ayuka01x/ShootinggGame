#include "EnemyEffect.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// Player画像
  /// </summary>
  const char* kEnemyEffect = "Assets/Image/Battle/Effect/ExplosionEffect.png";

  /// <summary>
  /// ４分割
  /// </summary>
  const int kEnemyFull = 4;

  /// <summary>
  /// ２分割
  /// </summary>
  const int kEnemyhalf = 2;

  /// <summary>
  /// フレームの秒数
  /// </summary>
  const float kFrame = 0.05f;

  /// <summary>
  /// 次のフレーム
  /// </summary>
  const int kFrameUp = 1;

  /// <summary>
  /// 打たない位置
  /// </summary>
  const int kEffectX = -50;

  /// <summary>
  /// 総フレーム
  /// </summary>
  const int AllFrame = 3;

}

/// <summary>
/// コンストラクタ
/// </summary>
EnemyEffect::EnemyEffect()
  : enemy_effect_image_(0)
  , enemy_effect_width_(0)
  , enemy_effect_height_(0)
  , enemy_effect_x_(0)
  , enemy_effect_y_(0)
  , frame_duration_(kFrame) {

}

/// <summary>
/// デストラクタ
/// </summary>
EnemyEffect::~EnemyEffect() {

}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void EnemyEffect::Initialize(float x, float y) {
  enemy_effect_x_ = x;
  enemy_effect_y_ = y;

  if (enemy_effect_image_ != 0) {
    DeleteGraph(enemy_effect_image_);
  }

  enemy_effect_image_ = LoadGraph(kEnemyEffect);
  GetGraphSize(enemy_effect_image_, &enemy_effect_width_, &enemy_effect_height_);


  LoadDivGraph(kEnemyEffect, kEnemyFull, kEnemyhalf, kEnemyhalf, enemy_effect_width_ / kEnemyhalf, enemy_effect_height_ / kEnemyhalf, enemy_effect_images_);

  is_enemy_effect_ = false;
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void EnemyEffect::Update(float delta_time) {
  elapsed_time_ += delta_time;

  // 0.05秒ごとにフレームを変更
  if (elapsed_time_ >= frame_duration_) {
    current_frame_ = (current_frame_ + kFrameUp) % kEnemyFull;
    elapsed_time_ = 0.0f;
  }
  if (current_frame_ >= AllFrame) {
    is_enemy_effect_ = false;
    current_frame_ = 0;
  }
}

/// <summary>
/// 描画
/// </summary>
void EnemyEffect::Render() {
  if (is_enemy_effect_) {
    if (enemy_effect_y_ != kEffectX) {
      DrawGraph(enemy_effect_x_, enemy_effect_y_, enemy_effect_images_[current_frame_], TRUE);
    }
 
  }
  
}

/// <summary>
/// エフェクト種類
/// </summary>
/// <returns></returns>
EffectManager::EffectKind EnemyEffect::GetEffectKind() {
  return EffectManager::EffectKind::kEnemyEffect;
}

/// <summary>
/// エフェクト発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void EnemyEffect::FireEffect(float x, float y) {

  enemy_effect_x_ = x;
  enemy_effect_y_ = y;
  is_enemy_effect_ = true;
}
