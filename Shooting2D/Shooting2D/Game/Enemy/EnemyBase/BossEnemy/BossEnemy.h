﻿#pragma once
#include "Game/Enemy/EnemyBase/EnemyBase.h"

/// <summary>
/// クラス
/// </summary>
class BossEnemy : public EnemyBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  BossEnemy();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~BossEnemy();

  /// <summary>
  /// 敵の初期化
  /// </summary>
  /// <param name="x">位置</param>
  /// <param name="y">位置</param>
  /// <param name="speed">速さ</param>
  /// <param name="image_path">画像</param>
  void Initialize(float x, float y, float speed, float time) override;

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
  /// 敵の種類取得
  /// </summary>
  /// <returns></returns>
  EnemyManager::EnemyKind GetEnemyKind() override;

  /// <summary>
  ///  弾が画面外に出たかどうかを判定
  /// </summary>
  /// <returns></returns>
  bool IsEnemyOutOfScreen();

  /// <summary>
  /// 動き
  /// </summary>
  /// <param name="tackle_enemy_x"></param>
  /// <param name="tackle_enemy_y"></param>
  void FireEnemy(float tackle_enemy_x, float tackle_enemy_y) override;

  /// <summary>
  /// 外に出たか設定
  /// </summary>
  /// <param name="is_tackle_enemy_out_of_screen"></param>
  void SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen) override;

  /// <summary>
  /// 発射されたかどうかを設定
  /// </summary>
  /// <param name="is_enemy_fired"></param>
  void SetEnemyFire(bool is_enemy_fired) override;
  /// <summary>
  /// ｘ座標取得
  /// </summary>
  /// <returns></returns>
  float GetX() override;

  /// <summary>
  /// y座標取得
  /// </summary>
  /// <returns></returns>
  float GetY() override;

  /// <summary>
  /// 横幅取得
  /// </summary>
  /// <returns></returns>
  float GetWidth() override;

  /// <summary>
  /// 弾があたったかどうか
  /// </summary>
  /// <param name="is_bullet_hit"></param>
  void SetBulletHit(bool is_bullet_hit)override;

  /// <summary>
  /// 出現時間取得
  /// </summary>
  /// <returns></returns>
  float GetTime() override;

  /// <summary>
  /// ボス死亡判定
  /// </summary>
  /// <param name="boss_death"></param>
  void SetBossDeath(bool boss_death) override;


  /// <summary>
  /// 敵のx座標
  /// </summary>
  float boss_enemy_x_;

  /// <summary>
  /// 敵のy座標
  /// </summary>
  float boss_enemy_y_;

  /// <summary>
  /// 敵の速度
  /// </summary>
  float boss_enemy_speed_;

  /// <summary>
  /// 敵の画像のハンドル
  /// </summary>
  int boss_enemy_image_;

  /// <summary>
  /// 敵の幅
  /// </summary>
  int boss_enemy_width_;

  /// <summary>
  /// 敵の高さ
  /// </summary>
  int boss_enemy_height_;

  /// <summary>
  /// 画面外に出たかどうかのフラグ
  /// </summary>
  bool is_boss_enemy_out_of_screen_;

  /// <summary>
  /// 当たり判定
  /// </summary>
  bool is_bullet_hit_;

  /// <summary>
  /// 経過時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// ボス時間
  /// </summary>
  float boss_time_;


};