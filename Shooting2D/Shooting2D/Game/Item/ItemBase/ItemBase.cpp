#include "ItemBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
ItemBase::ItemBase() {
}

/// <summary>
/// デストラクタ
/// </summary>
ItemBase::~ItemBase() {
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
/// <param name="time"></param>
void ItemBase::Initialize(float x, float y, float speed) {
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void ItemBase::Update(float delta_time) {
}

/// <summary>
/// 描画
/// </summary>
void ItemBase::Render() {
}

/// <summary>
/// 敵の種類
/// </summary>
/// <returns></returns>
ItemManager::ItemKind ItemBase::GetItemKind() {
  return item_kind_;
}

/// <summary>
/// 発射されたかどうか
/// </summary>
/// <returns></returns>
bool ItemBase::IsItemFired() {
  return false;
}

/// <summary>
/// アイテム発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void ItemBase::FireItem(float x, float y) {
}

/// <summary>
/// x座標
/// </summary>
/// <returns></returns>
float ItemBase::GetX() {
  return 0.0f;
}

/// <summary>
/// y座標
/// </summary>
/// <returns></returns>
float ItemBase::GetY() {
  return 0.0f;
}

/// <summary>
/// アイテムが発射されたか設定
/// </summary>
/// <param name="is_ite_fire"></param>
void ItemBase::SetItemFire(bool is_item_fire) {
}

/// <summary>
/// 外に出たかどうか
/// </summary>
/// <param name="is_item_out_of_screen"></param>
void ItemBase::SetItemOutOfScreen(bool is_item_out_of_screen) {
  is_item_speed_up_out_of_screen_ = is_item_out_of_screen;
}

/// <summary>
/// 時間取得
/// </summary>
/// <returns></returns>
float ItemBase::GetTime() {
  return 0.0f;
}
