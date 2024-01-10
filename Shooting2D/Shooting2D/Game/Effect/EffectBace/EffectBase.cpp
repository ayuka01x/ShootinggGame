#include "EffectBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
EffectBase::EffectBase()
  : is_effect_(false) {

}

/// <summary>
/// デストラクタ
/// </summary>
EffectBase::~EffectBase() {

}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void EffectBase::Initialize(float x, float y) {

}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void EffectBase::Update(float delta_time) {

}

/// <summary>
/// 描画
/// </summary>
void EffectBase::Render() {

}

/// <summary>
/// エフェクト済みかどうか
/// </summary>
/// <returns></returns>
bool EffectBase::IsEffect() {
  return is_effect_;
}

/// <summary>
/// エフェクト種類取得
/// </summary>
/// <returns></returns>
EffectManager::EffectKind EffectBase::GetEffectKind() {
  return effect_kind_;
}

/// <summary>
/// エフェクト発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void EffectBase::FireEffect(float x, float y) {

}

/// <summary>
/// エフェクト済みかどうか
/// </summary>
/// <returns></returns>
bool EffectBase::IsFinishEffect() {

  return is_effect_;
}
