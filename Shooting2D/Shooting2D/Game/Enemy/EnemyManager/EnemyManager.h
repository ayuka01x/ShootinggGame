#pragma once
#include "System/Task/Task.h"
#include <string> 

/// <summary>
/// 前方宣言
/// </summary>
class EnemyBase;

/// <summary>
/// 前方宣言
/// </summary>
class BossEnemy;
/// <summary>
/// クラス
/// </summary>
class EnemyManager : public Task {
public:

  /// <summary>
  /// 敵の種類
  /// </summary>
  enum class EnemyKind {

    /// <summary>
    /// タックルエネミー
    /// </summary>
    kTackleEnemy,

    /// <summary>
    /// ボスエネミー
    /// </summary>
    kBossEnemy,

    /// <summary>
    /// ミニボス
    /// </summary>
    kMiniBossEnemy,
  };
  /// <summary>
  /// 敵データ
  /// </summary>
  struct EnemyPlacement {
    /// <summary>
    /// 敵の種類
    /// </summary>
    EnemyKind type;

    /// <summary>
    /// 出現時間
    /// </summary>
    float in_time;

    /// <summary>
    /// ｘ座標
    /// </summary>
    float x;

    /// <summary>
    /// ｙ座標
    /// </summary>
    float y;

    /// <summary>
    /// 生成済みかどうか
    /// </summary>
    bool spawned = false;

  };

  /// <summary>
  /// コンストラクタ
  /// </summary>
  EnemyManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~EnemyManager();

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// 作成した敵を削除する
  /// </summary>
  void DestroyEnemy();

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
  /// エネミー発射
  /// </summary>
  /// <param name="kind"></param>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void EnemyFire(EnemyKind kind);

  /// <summary>
  /// ボスX座標取得
  /// </summary>
  /// <returns></returns>
  float GetBossX();

  /// <summary>
  /// 敵情報
  /// </summary>
  /// <param name="filename"></param>
  void LoadEnemyPlacement(const std::string filename);


  /// <summary>
  /// 敵
  /// </summary>
  std::vector<EnemyBase*> enemy_list_;

  /// <summary>
  /// 更新時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// 最初の敵の初期X位置
  /// </summary>
  float start_x_;

  /// <summary>
  /// 最初の敵の初期Y位置
  /// </summary>
  float start_y_;

  /// <summary>
  ///  敵と敵の間の横のスペース
  /// </summary>
  float spacing_x_;

  /// <summary>
  /// 敵と敵の間の縦のスペース
  /// </summary>
  float spacing_y_;

  /// <summary>
  /// ボスx座標
  /// </summary>
  float boss_x_;

  /// <summary>
  /// ボスy座標
  /// </summary>
  float boss_y_;

  /// <summary>
  /// ボス
  /// </summary>
  BossEnemy* boss_enemy_;

  /// <summary>
  /// 敵リスト
  /// </summary>
  std::vector<EnemyPlacement> enemy_placement_data_;

};