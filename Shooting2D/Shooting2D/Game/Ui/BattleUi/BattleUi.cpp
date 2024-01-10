#include "BattleUi.h"
#include "DxLib.h"
/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// ゲームクリア画像
  /// </summary>
  const char* kGameClearImage = "Assets/Image/Ui/BattleUi/GameClearImage.png";

  /// <summary>
  /// ゲームオーバー画像
  /// </summary>
  const char* kGameOverImage = "Assets/Image/Ui/BattleUi/GameOverImage.png";

  /// <summary>
  /// クリアｘ座標
  /// </summary>
  const int kClearImageX = 435;

  /// <summary>
  /// クリアy座標
  /// </summary>
  const int kClearImageY = 320;
}

/// <summary>
/// コンストラクタ
/// </summary>
BattleUi::BattleUi()
  : game_clear_image_()
  , game_over_image_()
  , game_clear_width_()
  , game_clear_height_()
  , game_over_width_()
  , game_over_height_()
  , game_clear_x_()
  , game_clear_y_()
  , game_over_x_()
  , game_over_y_()
  , game_clear_(false)
  , game_over_(false) {

}

/// <summary>
/// デストラクタ
/// </summary>
BattleUi::~BattleUi() {

}

/// <summary>
/// 初期化
/// </summary>
void BattleUi::Initialize() {
  game_clear_image_ = LoadGraph(kGameClearImage);
  game_over_image_ = LoadGraph(kGameOverImage);

  GetGraphSize(game_clear_image_, &game_clear_width_, &game_clear_height_);
  GetGraphSize(game_over_image_, &game_over_width_, &game_over_height_);

  game_clear_x_ = kClearImageX;
  game_clear_y_ = kClearImageY;

  game_over_x_ = kClearImageX;
  game_over_y_ = kClearImageY;
}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void BattleUi::Update(float delta_time) {

}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void BattleUi::Render() {
  if (game_clear_) {
    DrawGraph(game_clear_x_, game_clear_y_, game_clear_image_, TRUE);
  }
  
  if (game_over_) {
    DrawGraph(game_over_x_, game_over_y_, game_over_image_, TRUE);
  }
  
}

/// <summary>
/// 破棄
/// </summary>
void BattleUi::DestroyBatttlUi() {
  DeleteGraph(game_clear_image_);
  DeleteGraph(game_over_image_);
}

/// <summary>
/// セットゲームクリア
/// </summary>
/// <param name="game_clear"></param>
void BattleUi::SetGameClear(bool game_clear) {
  game_clear_ = game_clear;
}

/// <summary>
/// セットゲームオーバー
/// </summary>
/// <param name="game_over"></param>
void BattleUi::SetGameOver(bool game_over) {
  game_over_ = game_over;
}
