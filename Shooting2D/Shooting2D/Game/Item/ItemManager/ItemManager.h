#pragma once
#include "System/Task/Task.h"
#include <string> 

/// <summary>
/// 前方宣言
/// </summary>
class ItemBase;

/// <summary>
/// クラス
/// </summary>
class ItemManager : public Task {
public:

  /// <summary>
  /// 敵の種類
  /// </summary>
  enum class ItemKind {

    /// <summary>
    /// 速度を上げる
    /// </summary>
    kSpeedUp,
  };
  

  /// <summary>
  /// コンストラクタ
  /// </summary>
  ItemManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~ItemManager();

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// 削除
  /// </summary>
  void DestroyItem();

  /// <summary>
  /// 更新
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// アイテム発射
  /// </summary>
  /// <param name="kind"></param>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void ItemFire(ItemKind kind, float x, float y);

  /// <summary>
  /// 敵
  /// </summary>
  std::vector<ItemBase*> item_list_;

  /// <summary>
  /// 更新時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// アイテムのX位置
  /// </summary>
  int start_x_;


};