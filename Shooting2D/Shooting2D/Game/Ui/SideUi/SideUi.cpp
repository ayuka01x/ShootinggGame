#include "SideUi.h"
#include "DxLib.h"
/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// サイド画像
  /// </summary>
  const char* kSideImage = "Assets/Image/Ui/SideUi/SideUiBg02.png";

  /// <summary>
  /// サイド画像のｘ座標
  /// </summary>
  const int kSideRightImage = 1080;
}

/// <summary>
/// コンストラクタ
/// </summary>
SideUi::SideUi()
  : side_image_()
  , side_width_()
  , side_height_()
  , side_x_()
  , side_y_() {

}

/// <summary>
/// デストラクタ
/// </summary>
SideUi::~SideUi() {

}

/// <summary>
/// 初期化
/// </summary>
void SideUi::Initialize() {
  side_image_ = LoadGraph(kSideImage);

  GetGraphSize(side_image_, &side_width_, &side_height_);
}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void SideUi::Update(float delta_time) {

}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void SideUi::Render() {
  DrawGraph(0, side_y_, side_image_, TRUE);
  DrawGraph(kSideRightImage, side_y_, side_image_, TRUE);
}

/// <summary>
/// 破棄
/// </summary>
void SideUi::DestroySideUi() {
  DeleteGraph(side_image_);
}
