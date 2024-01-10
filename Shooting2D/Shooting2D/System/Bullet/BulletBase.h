#pragma once
#include <string>
#include "System/Task/BulletManager/BulletManager.h"


/// <summary>
/// クラス
/// </summary>
class BulletBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  BulletBase();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~BulletBase();

  /// <summary>
  /// 弾の初期化
  /// </summary>
  /// <param name="x">位置</param>
  /// <param name="y">位置</param>
  /// <param name="speed">速さ</param>
  /// <param name="image_path">画像</param>
  virtual void Initialize(float x, float y, float speed);

  /// <summary>
  ///  弾の更新処理
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// 弾の描画処理
  /// </summary>
  virtual void Render();

  /// <summary>
  /// 発射済みかどうかを返す関数
  /// </summary>
  /// <param name="is_fired"></param>
  bool IsFired();

  /// <summary>
  /// 弾の種類
  /// </summary>
  /// <returns></returns>
  virtual BulletManager::BulletKind GetBulletKind();

  /// <summary>
  /// 発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void FireBullet(float x, float y);

  /// <summary>
  /// 弾が外に出たかどうか
  /// </summary>
  /// <returns></returns>
  virtual bool IsOutOfScreen();

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
  /// 弾が発射されたかどうかを設定
  /// </summary>
  /// <param name="fired"></param>
  virtual void SetFired(bool fired);

  /// <summary>
  /// 外に出たかどうか
  /// </summary>
  /// <param name="out_of_screen"></param>
  virtual void SetIsOutOfScreen(bool out_of_screen);

  /// <summary>
  /// 弾の座標を設定する関数
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void SetPosition(float x, float y);

  /// <summary>
  /// 発射済みかどうか
  /// </summary>
  bool is_fired_;

  /// <summary>
  /// 弾の種類
  /// </summary>
  BulletManager::BulletKind bullet_kind_;


};
