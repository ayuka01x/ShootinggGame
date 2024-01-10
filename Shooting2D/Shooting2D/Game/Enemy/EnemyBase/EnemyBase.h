#pragma once
#include "Game/Enemy/EnemyManager/EnemyManager.h"
#include <string>
/// <summary>
/// クラス
/// </summary>
class EnemyBase {
public:
  

  /// <summary>
  /// コンストラクタ
  /// </summary>
  EnemyBase();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~EnemyBase();

  /// <summary>
  /// 敵の初期化
  /// </summary>
  /// <param name="x">位置</param>
  /// <param name="y">位置</param>
  /// <param name="speed">速さ</param>
  /// <param name="image_path">画像</param>
  virtual void Initialize(float x, float y, float speed, float time);

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
  /// 敵の種類取得
  /// </summary>
  /// <returns></returns>
  virtual EnemyManager::EnemyKind GetEnemyKind();

  /// <summary>
  /// 敵出現
  /// </summary>
  /// <returns></returns>
  bool IsEnemyFired();

  /// <summary>
  /// 敵が動く
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void FireEnemy(float x, float y);


  /// <summary>
  /// ｘ座標取得
  /// </summary>
  /// <returns></returns>
  virtual float GetX();

  /// <summary>
  /// y座標取得
  /// </summary>
  /// <returns></returns>
  virtual float GetY();

  /// <summary>
  /// 横幅取得
  /// </summary>
  /// <returns></returns>
  virtual float GetWidth();


  /// <summary>
  /// 敵が発射されたか設定
  /// </summary>
  /// <param name="is_enemy_fired"></param>
  virtual void SetEnemyFire(bool is_enemy_fired);

  /// <summary>
  /// 外に出たかどうか設定
  /// </summary>
  /// <param name="is_tackle_enemy_out_of_screen"></param>
  virtual void SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen);

  /// <summary>
  /// 弾が当たったかどうか
  /// </summary>
  virtual void SetBulletHit(bool is_bullet_hit);

  /// <summary>
  /// 出現時間取得
  /// </summary>
  virtual float GetTime();

  /// <summary>
  /// ボスが死んだか
  /// </summary>
  /// <param name="boss_death"></param>
  virtual void SetBossDeath(bool boss_death);

  /// <summary>
  /// ミニボスが死んだかどうか
  /// </summary>
  /// <param name="miniboss_death"></param>
  virtual void SetMiniBossDeath(bool miniboss_death);
  /// <summary>
  /// 敵の種類
  /// </summary>
  EnemyManager::EnemyKind enemy_kind_;

  /// <summary>
  /// 敵出現したかどうか
  /// </summary>
  bool is_enemy_fired_;

  /// <summary>
  /// 弾が当たったかどうか
  /// </summary>
  bool is_bullet_hit_;

  /// <summary>
  /// ボスが死んだかどうか
  /// </summary>
  bool boss_death_;

  /// <summary>
  /// ミニボスが死んだかどうか
  /// </summary>
  bool miniboss_death_;

};