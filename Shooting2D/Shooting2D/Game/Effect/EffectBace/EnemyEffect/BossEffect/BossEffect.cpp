#include "BossEffect.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// Player画像
  /// </summary>
  const char* kBossEffect = "Assets/Image/Battle/Effect/ExplosionEffect.png";

  /// <summary>
  /// ４分割
  /// </summary>
  const int kBossFull = 4;

  /// <summary>
  /// ２分割
  /// </summary>
  const int kBosshalf = 2;

  /// <summary>
  /// 爆発座標
  /// </summary>
  const int kBossPosition = 25;

  /// <summary>
  /// フレーム秒数
  /// </summary>
  const float kFrame = 0.05f;

  /// <summary>
  /// 次のフレーム
  /// </summary>
  const int kFrameUp = 1;

  /// <summary>
  /// フレーム総数
  /// </summary>
  const int kAllFrame = 3;

}

/// <summary>
/// コンストラクタ
/// </summary>
BossEffect::BossEffect()
  : boss_effect_image_(0)
  , boss_effect_width_(0)
  , boss_effect_height_(0)
  , boss_effect_x_(0)
  , boss_effect_y_(0)
  , frame_duration_(kFrame) {

}

/// <summary>
/// デストラクタ
/// </summary>
BossEffect::~BossEffect() {

}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BossEffect::Initialize(float x, float y) {
  boss_effect_x_ = x;
  boss_effect_y_ = y;

  if (boss_effect_image_ != 0) {
    DeleteGraph(boss_effect_image_);
  }

  boss_effect_image_ = LoadGraph(kBossEffect);
  GetGraphSize(boss_effect_image_, &boss_effect_width_, &boss_effect_height_);


  LoadDivGraph(kBossEffect, kBossFull, kBosshalf, kBosshalf, boss_effect_width_ / kBosshalf, boss_effect_height_ / kBosshalf, boss_effect_images_);

  is_enemy_effect_ = false;
  boss_death_ = false;
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void BossEffect::Update(float delta_time) {

  elapsed_time_ += delta_time;
  if (is_enemy_effect_) {
    // 0.05秒ごとにフレームを変更
    if (elapsed_time_ >= frame_duration_) {
      current_frame_ = (current_frame_ + kFrameUp) % kBossFull;
      elapsed_time_ = 0.0f;
    }
  }
  
  if (current_frame_ >= kAllFrame) {
    is_enemy_effect_ = false;
    current_frame_ = 0;
    boss_death_ = true;
  }
}

/// <summary>
/// 描画
/// </summary>
void BossEffect::Render() {
  if (is_enemy_effect_) {
    int boss_x_positoin[] = { kBossPosition,kBossPosition,-kBossPosition,-kBossPosition,0 };
    int boss_y_positoin[] = { kBossPosition,-kBossPosition,kBossPosition,-kBossPosition,0 };

    for (int i = 0; i < kBossFull; ++i) {
      DrawGraph(boss_effect_x_ + boss_x_positoin[i], boss_effect_y_ + boss_y_positoin[i], boss_effect_images_[current_frame_], TRUE);
      
    }

  }
  
}

/// <summary>
/// エフェクト種類
/// </summary>
/// <returns></returns>
EffectManager::EffectKind BossEffect::GetEffectKind() {

  return EffectManager::EffectKind::kBossEffect;
}

/// <summary>
/// エフェクト発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BossEffect::FireEffect(float x, float y) {

  if (!boss_death_) {
    boss_effect_x_ = x + kBossPosition;
    boss_effect_y_ = y + kBossPosition;
    is_enemy_effect_ = true;
  }
  
}