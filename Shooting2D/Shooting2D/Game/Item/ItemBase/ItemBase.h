#pragma once
#include "Game/Item/ItemManager/ItemManager.h"

/// <summary>
/// クラス
/// </summary>
class ItemBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  ItemBase();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~ItemBase();

  /// <summary>
  /// 初期化
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  /// <param name="speed"></param>
  /// <param name="time"></param>
  virtual void Initialize(float x, float y, float speed);

  /// <summary>
  ///  敵の更新処理
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// 敵の描画処理
  /// </summary>
  virtual void Render();

  /// <summary>
  /// 種類取得
  /// </summary>
  /// <returns></returns>
  virtual ItemManager::ItemKind GetItemKind();

  /// <summary>
  /// 発射されたかどうか
  /// </summary>
  /// <returns></returns>
  bool IsItemFired();

  /// <summary>
  /// アイテム発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void FireItem(float x, float y);

  /// <summary>
  /// x座標
  /// </summary>
  /// <returns></returns>
  virtual float GetX();

  /// <summary>
  /// y座標
  /// </summary>
  /// <returns></returns>
  virtual float GetY();

  /// <summary>
  /// アイテムが発射されたか設定
  /// </summary>
  /// <param name="is_ite_fire"></param>
  virtual void SetItemFire(bool is_item_fire);

  /// <summary>
  /// 外に出たかどうか
  /// </summary>
  /// <param name="is_item_out_of_screen"></param>
  virtual void SetItemOutOfScreen(bool is_item_out_of_screen);

  /// <summary>
  /// 時間取得
  /// </summary>
  /// <returns></returns>
  virtual float GetTime();

  /// <summary>
  /// アイテムの種類
  /// </summary>
  ItemManager::ItemKind item_kind_;

  /// <summary>
  /// アイテムが出現したか
  /// </summary>
  bool is_item_fire_;

  /// <summary>
  /// 画面外に出たかどうかのフラグ
  /// </summary>
  bool is_item_speed_up_out_of_screen_;

};