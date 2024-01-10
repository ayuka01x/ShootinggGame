#include "Game/Effect/EffectBace/PlayerEffect/PlayerEffect.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// Player画像
  /// </summary>
  const char* kPlayerEffect = "Assets/Image/Battle/Effect/PlayerDeathEffect.png";

  /// <summary>
  /// ４分割
  /// </summary>
  const int kPlayerFull = 4;

  /// <summary>
  /// ２分割
  /// </summary>
  const int kPlayerhalf = 2;

  /// <summary>
  /// フレーム秒数
  /// </summary>
  const float kFrame = 0.08f;

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
PlayerEffect::PlayerEffect()
  : player_effect_image_(0)
  , player_effect_width_(0)
  , player_effect_height_(0)
  , player_effect_x_(0)
  , player_effect_y_(0)
  , frame_duration_(kFrame) {

}

/// <summary>
/// デストラクタ
/// </summary>
PlayerEffect::~PlayerEffect() {

}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void PlayerEffect::Initialize(float x, float y) {
  player_effect_x_ = x;
  player_effect_y_ = y;

  if (player_effect_image_ != 0) {
    DeleteGraph(player_effect_image_);
  }

  player_effect_image_ = LoadGraph(kPlayerEffect);
  GetGraphSize(player_effect_image_, &player_effect_width_, &player_effect_height_);


  LoadDivGraph(kPlayerEffect, kPlayerFull, kPlayerhalf, kPlayerhalf, player_effect_width_ / kPlayerhalf, player_effect_height_ / kPlayerhalf, player_effect_images_);

  is_player_effect_ = false;
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void PlayerEffect::Update(float delta_time) {

  elapsed_time_ += delta_time;

  // 0.05秒ごとにフレームを変更
  if (elapsed_time_ >= frame_duration_) {
    current_frame_ = (current_frame_ + kFrameUp) % kPlayerFull;
    elapsed_time_ = 0.0f;
  }
}

/// <summary>
/// 描画
/// </summary>
void PlayerEffect::Render() {
  if (is_player_effect_) {
    DrawGraph(player_effect_x_, player_effect_y_, player_effect_images_[current_frame_], TRUE);

  }
  if (current_frame_ >= kAllFrame) {
    is_player_effect_ = false;
    
  }
}

/// <summary>
/// エフェクト種類
/// </summary>
/// <returns></returns>
EffectManager::EffectKind PlayerEffect::GetEffectKind() {

  return EffectManager::EffectKind::kPlayerEffect;
}

/// <summary>
/// エフェクト発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void PlayerEffect::FireEffect(float x, float y) {

  player_effect_x_ = x;
  player_effect_y_ = y;
  is_player_effect_ = true;
}
