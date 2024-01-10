#include "ItemManager.h"
#include"Game/Item/ItemBase/SpeedUp/SpeedUp.h"
#include <ctime>
#include <random>
/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// アイテム総数
  /// </summary>
  const int kItemMax = 1;

  /// <summary>
  /// 初期位置
  /// </summary>
  const int kSpeedUpInitialize = -500;
}
/// <summary>
/// コンストラクタ
/// </summary>
ItemManager::ItemManager() {
}

/// <summary>
/// デストラクタ
/// </summary>
ItemManager::~ItemManager() {
}

/// <summary>
/// 初期化
/// </summary>
void ItemManager::Initialize() {
  for (int i = 0; i < kItemMax; ++i) {
    SpeedUp* speed_up = new SpeedUp();

    speed_up->Initialize(kSpeedUpInitialize, kSpeedUpInitialize, 0);

    item_list_.push_back(speed_up);
  }
}

/// <summary>
/// 消去
/// </summary>
void ItemManager::DestroyItem() {
  for (int i = 0; i < kItemMax; ++i) {
    if (item_list_[i] != nullptr) {
      delete item_list_[i];
      item_list_[i] = nullptr;
    }

  }
  item_list_.clear();
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void ItemManager::Update(float delta_time) {
  for (int i = 0; i < kItemMax; ++i) {
    if (item_list_[i] != nullptr) {
      item_list_[i]->Update(delta_time);
    }

  }
}

/// <summary>
/// 描画処理
/// </summary>
void ItemManager::Render() {
  for (int i = 0; i < kItemMax; ++i) {
    if (item_list_[i] != nullptr) {
      item_list_[i]->Render();
    }
  }
}

/// <summary>
/// アイテム発射
/// </summary>
/// <param name="kind"></param>
void ItemManager::ItemFire(ItemKind kind, float x, float y){

  for (std::vector<ItemBase*>::iterator itr = item_list_.begin(); itr != item_list_.end(); ++itr) {
    if ((*itr)->GetItemKind() != kind) {

      continue;
    }

    if ((*itr)->IsItemFired()) {
      continue;
    }

    (*itr)->FireItem(x, y);
    break;

  }

}
