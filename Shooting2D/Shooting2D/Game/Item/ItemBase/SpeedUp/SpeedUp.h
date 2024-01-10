#pragma once
#include "Game/Item/ItemBase/ItemBase.h"

/// <summary>
/// クラス
/// </summary>
class SpeedUp : public ItemBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  SpeedUp();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~SpeedUp();


  /// <summary>
  /// 初期化
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  /// <param name="speed"></param>
  /// <param name="time"></param>
  void Initialize(float x, float y, float speed) override;

  /// <summary>
  ///  敵の更新処理
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 敵の描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// 種類取得
  /// </summary>
  /// <returns></returns>
  ItemManager::ItemKind GetItemKind() override;

  /// <summary>
  /// アイテム発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void FireItem(float x, float y) override;

  /// <summary>
  /// x座標
  /// </summary>
  /// <returns></returns>
  float GetX() override;

  /// <summary>
  /// y座標
  /// </summary>
  /// <returns></returns>
  float GetY() override;

  /// <summary>
  /// アイテムが発射されたか設定
  /// </summary>
  /// <param name="is_ite_fire"></param>
  void SetItemFire(bool is_item_fire) override;

  /// <summary>
  /// 外に出たかどうか
  /// </summary>
  /// <param name="is_item_out_of_screen"></param>
  void SetItemOutOfScreen(bool is_item_out_of_screen) override;

  /// <summary>
  /// 敵のx座標
  /// </summary>
  float item_speed_up_x_;

  /// <summary>
  /// 敵のy座標
  /// </summary>
  float item_speed_up_y_;

  /// <summary>
  /// 敵の速度
  /// </summary>
  float item_speed_up_speed_;

  /// <summary>
  /// 敵の画像のハンドル
  /// </summary>
  int item_speed_up_image_;

  /// <summary>
  /// 敵の幅
  /// </summary>
  int item_speed_up_width_;

  /// <summary>
  /// 敵の高さ
  /// </summary>
  int item_speed_up_height_;

  
};