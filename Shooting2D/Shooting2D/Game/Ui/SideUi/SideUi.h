#pragma once
#include "System/Task/Task.h"

/// <summary>
/// サイドUIクラス
/// </summary>
class SideUi : public Task {
public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  SideUi();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~SideUi();

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// 毎フレームの更新処理
  /// </summary>
  /// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
  void Update(float delta_time) override;

  /// <summary>
  /// 毎フレームの描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// 破棄
  /// </summary>
  void DestroySideUi();

private:

  /// <summary>
  /// ゲームオーバー
  /// </summary>
  int side_image_;

  /// <summary>
  /// ゲームクリア横幅
  /// </summary>
  int side_width_;

  /// <summary>
  /// ゲームクリア縦幅
  /// </summary>
  int side_height_;

  /// <summary>
  /// サイドｘ座標
  /// </summary>
  int side_x_;

  /// <summary>
  /// サイドｙ座標
  /// </summary>
  int side_y_;

};