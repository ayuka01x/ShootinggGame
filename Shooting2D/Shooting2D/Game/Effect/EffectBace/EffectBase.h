#pragma once
#include "Game/Effect/EffectManager/EffectManager.h"

/// <summary>
/// クラス
/// </summary>
class EffectBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  EffectBase();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~EffectBase();

  /// <summary>
  /// 初期化
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void Initialize(float x, float y);

  /// <summary>
  ///  更新処理
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// 描画処理
  /// </summary>
  virtual void Render();

  /// <summary>
  /// エフェクト済みかどうか
  /// </summary>
  /// <returns></returns>
  bool IsEffect();

  /// <summary>
  /// エフェクト種類取得
  /// </summary>
  /// <returns></returns>
  virtual EffectManager::EffectKind GetEffectKind();

  /// <summary>
  /// エフェクト種類
  /// </summary>
  EffectManager::EffectKind effect_kind_;

  /// <summary>
  /// エフェクト発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void FireEffect(float x, float y);

  /// <summary>
  /// エフェクト済みかどうか
  /// </summary>
  /// <returns></returns>
  bool IsFinishEffect();

  /// <summary>
  /// エフェクト済みかどうか
  /// </summary>
  bool is_effect_;

};