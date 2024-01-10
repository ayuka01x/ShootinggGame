#pragma once
#include "System/Task/Task.h"
#include <string>
#include <vector>

/// <summary>
/// 前方宣言
/// </summary>
class EffectBase;

/// <summary>
/// クラス
/// </summary>
class EffectManager : public Task {
public:

  /// <summary>
  /// エフェクト種類
  /// </summary>
  enum class EffectKind {

    /// <summary>
    /// プレイヤーエフェクト
    /// </summary>
    kPlayerEffect,

    /// <summary>
    /// 敵エフェクト
    /// </summary>
    kEnemyEffect,

    /// <summary>
    /// boss
    /// </summary>
    kBossEffect,

  };

  /// <summary>
  /// コンストラクタ
  /// </summary>
  EffectManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~EffectManager();

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// 消去
  /// </summary>
  void DestroyEffect();

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
  /// エフェクト出力
  /// </summary>
  void EffectFire(EffectKind kind, float x, float y);

  /// <summary>
  /// EffectBaseのポインタ
  /// </summary>
  std::vector<EffectBase*> effect_list_;
  
};