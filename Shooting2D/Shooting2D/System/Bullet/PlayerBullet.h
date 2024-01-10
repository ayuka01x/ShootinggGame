#pragma once
#include "BulletBase.h"
#include <string>

/// <summary>
/// クラス
/// </summary>
class PlayerBullet : public BulletBase {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  PlayerBullet();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~PlayerBullet();

  /// <summary>
  /// プレイヤー弾の初期化関数
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  /// <param name="speed"></param>
  /// <param name="image_path"></param>
  void Initialize(float x, float y, float speed) override;

  /// <summary>
  /// 更新処理
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time) override;

  /// <summary>
  /// 描画
  /// </summary>
  void Render() override;

  /// <summary>
  /// 弾の種類
  /// </summary>
  /// <returns></returns>
  BulletManager::BulletKind GetBulletKind();

  /// <summary>
  /// 弾の発射
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void FireBullet(float x, float y) override;

  /// <summary>
  ///  弾が画面外に出たかどうかを判定
  /// </summary>
  /// <returns></returns>
  bool IsOutOfScreen() override;

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
  float GetWidth()override;

  /// <summary>
  /// 弾が発射されたかどうかを設定
  /// </summary>
  /// <param name="fired">発射されたかどうかのフラグ</param>
  void SetFired(bool fired) override;

  /// <summary>
  /// 外に出たかどうか設定
  /// </summary>
  /// <param name="out_of_screen"></param>
  void SetIsOutOfScreen(bool out_of_screen) override;

  /// <summary>
  ///  弾の座標を設定する関数
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void SetPosition(float x, float y) override;

  /// <summary>
  /// 弾のx座標
  /// </summary>
  float bullet_x_;

  /// <summary>
  /// 弾のy座標
  /// </summary>
  float bullet_y_;

  /// <summary>
  /// 弾の速度
  /// </summary>
  float bullet_speed_;

  /// <summary>
  /// 弾の画像のハンドル
  /// </summary>
  int bullet_image_;

  /// <summary>
  /// 弾の幅
  /// </summary>
  int bullet_width_;

  /// <summary>
  /// 弾の高さ
  /// </summary>
  int bullet_height_;

  /// <summary>
  /// 画面外に出たかどうかのフラグ
  /// </summary>
  bool is_out_of_screen_;

  /// <summary>
  /// 円の半径
  /// </summary>
  float bullet_radius_;
};