#pragma once
#include "System/Task/Task.h"

/// <summary>
/// バトルUI
/// </summary>
class BattleUi : public Task {

public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  BattleUi();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~BattleUi();


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
  void DestroyBatttlUi();

  /// <summary>
  /// セットゲームクリア
  /// </summary>
  /// <param name="game_clear"></param>
  void SetGameClear(bool game_clear);

  /// <summary>
  /// セットゲームオーバー
  /// </summary>
  /// <param name="game_over"></param>
  void SetGameOver(bool game_over);
private:
  /// <summary>
  /// ゲームクリア
  /// </summary>
  int game_clear_image_;

  /// <summary>
  /// ゲームオーバー
  /// </summary>
  int game_over_image_;

  /// <summary>
  /// ゲームクリア横幅
  /// </summary>
  int game_clear_width_;

  /// <summary>
  /// ゲームクリア縦幅
  /// </summary>
  int game_clear_height_;

  /// <summary>
  /// ゲームオーバー縦幅
  /// </summary>
  int game_over_width_;

  /// <summary>
  /// ゲームオーバー横幅
  /// </summary>
  int game_over_height_;

  /// <summary>
  /// ゲームクリアｘ座標
  /// </summary>
  int game_clear_x_;

  /// <summary>
  /// ゲームクリアｙ座標
  /// </summary>
  int game_clear_y_;

  /// <summary>
  /// ゲームオーバーｘ座標
  /// </summary>
  int game_over_x_;

  /// <summary>
  /// ゲームオーバーｙ座標
  /// </summary>
  int game_over_y_;

  /// <summary>
  /// クリアしたかどうか
  /// </summary>
  bool game_clear_;

  /// <summary>
  /// ゲームオーバーかどうか
  /// </summary>
  bool game_over_;
};