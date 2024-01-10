#include "EffectManager.h"
#include "Game/Effect/EffectBace/PlayerEffect/PlayerEffect.h"
#include "Game/Effect/EffectBace/EnemyEffect/EnemyEffect.h"
#include "Game/Effect/EffectBace/EnemyEffect/BossEffect/BossEffect.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// プレイヤーエフェクト総数
  /// </summary>
  const int kplayerEffectAll = 3;

  /// <summary>
  /// エフェクト総数
  /// </summary>
  const int kAllEffect = 9;
}

EffectManager::EffectManager() {

}

EffectManager::~EffectManager() {

}

void EffectManager::Initialize() {
  for (int i = 0; i < kplayerEffectAll; ++i) {
    PlayerEffect* player_effect = new PlayerEffect();

    player_effect->Initialize(0, 0);

    effect_list_.push_back(player_effect);
  }
  for (int i = 0; i < kplayerEffectAll; ++i) {
    EnemyEffect* enemy_effect = new EnemyEffect();

    enemy_effect->Initialize(0, 0);

    effect_list_.push_back(enemy_effect);
  }

  for (int i = 0; i < kplayerEffectAll; ++i) {
    BossEffect* enemy_effect = new BossEffect();

    enemy_effect->Initialize(0, 0);

    effect_list_.push_back(enemy_effect);
  }
}

void EffectManager::DestroyEffect() {
  for (int i = 0;i < kAllEffect;++i) {
    if (effect_list_[i] != nullptr) {
      delete effect_list_[i];
      effect_list_[i] = nullptr;
    }
  }
  effect_list_.clear();
}

void EffectManager::Update(float delta_time) {
  for (int i = 0;i < kAllEffect;++i) {
    if (effect_list_[i] != nullptr) {
      effect_list_[i]->Update(delta_time);
    }
  }
}

void EffectManager::Render() {
  for (int i = 0;i < kAllEffect;++i) {
    if (effect_list_[i] != nullptr) {
      effect_list_[i]->Render();
    }
  }
}

void EffectManager::EffectFire(EffectKind kind, float x, float y) {
  for (std::vector<EffectBase*>::iterator itr = effect_list_.begin(); itr != effect_list_.end(); ++itr) {
    if ((*itr)->GetEffectKind() != kind) {
      continue;
    }
    if ((*itr)->IsEffect()) {
      continue;
    }
    (*itr)->FireEffect(x, y);

    break;
  }  
}
