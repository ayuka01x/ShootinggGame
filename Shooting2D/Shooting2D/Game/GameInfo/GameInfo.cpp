#include "GameInfo.h"


/// <summary>
/// コンストラクタ
/// </summary>
GameInfo::GameInfo()
  :x_resolution_(kResolutionX)
  ,y_resolution_(kResolutionY)
  ,x_center_(kResolutionX / kHalf)
  ,y_center_(kResolutionY / kHalf)
  ,color_bit_(kColorBit) {

}

/// <summary>
/// デストラクタ
/// </summary>
GameInfo::~GameInfo() {

}

/// <summary>
/// ゲーム情報インスタンス
/// </summary>
GameInfo* GameInfo::instance_ = nullptr;

/// <summary>
/// 解像度の横幅サイズ
/// </summary>
/// <returns></returns>
int GameInfo::GetResolutionX() {
  return x_resolution_;
}

/// <summary>
/// 解像度の縦幅サイズ
/// </summary>
/// <returns></returns>
int GameInfo::GetResolutionY() {
  return y_resolution_;
}

/// <summary>
/// 画面横幅の中心座標
/// </summary>
/// <returns></returns>
int GameInfo::GetCenterX() {
  return x_center_;
}

/// <summary>
/// 画面縦幅の中心座標
/// </summary>
/// <returns></returns>
int GameInfo::GetCenterY() {
  return y_center_;
}

/// <summary>
/// カラービット数
/// </summary>
/// <returns></returns>
int GameInfo::GetColorBit() {
  return color_bit_;
}
