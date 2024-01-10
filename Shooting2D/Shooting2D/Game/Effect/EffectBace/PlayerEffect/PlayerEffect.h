#pragma once
#pragma once
#include "Game/Effect/EffectBace/EffectBase.h"

/// <summary>
/// クラス
/// </summary>
class PlayerEffect : public EffectBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  PlayerEffect();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~PlayerEffect();

  /// <summary>
  /// 初期化
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void Initialize(float x, float y) override;

  /// <summary>
  /// 更新
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 描画
  /// </summary>
  void Render() override;

  /// <summary>
  /// エフェクト種類取得
  /// </summary>
  /// <returns></returns>
  EffectManager::EffectKind GetEffectKind() override;

  /// <summary>
  /// エフェクト発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void FireEffect(float x, float y) override;

private:

  /// <summary>
  /// 爆発の順番の種類
  /// </summary>
  enum class PlayerEffectKind {

    /// <summary>
    /// 1番
    /// </summary>
    First,

    /// <summary>
    /// ２番
    /// </summary>
    Second,

    /// <summary>
    /// ３番
    /// </summary>
    Third,

    /// <summary>
    /// ４番
    /// </summary>
    Forth,
  };

  /// <summary>
  /// 画像
  /// </summary>
  int player_effect_image_;

  /// <summary>
  /// 横幅
  /// </summary>
  int player_effect_width_;

  /// <summary>
  /// 立幅
  /// </summary>
  int player_effect_height_;

  /// <summary>
  /// ｘ座標
  /// </summary>
  float player_effect_x_;

  /// <summary>
  /// ｙ座標
  /// </summary>
  float player_effect_y_;

  /// <summary>
  /// 画像の配列
  /// </summary>
  int player_effect_images_[static_cast <int>(PlayerEffectKind::Forth)];

  /// <summary>
  /// 経過時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// フレーム毎に
  /// </summary>
  float frame_duration_;

  /// <summary>
  /// フレーム数
  /// </summary>
  int current_frame_;

  /// <summary>
  /// エフェクト発生
  /// </summary>
  bool is_player_effect_;
};