#include "SpeedUp.h"
#include "DxLib.h"

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// SpeedUp画像
  /// </summary>
  const char* kSpeedUpImage = "Assets/Image/Item/SpeedUpItem.png";

  /// <summary>
  /// 縦の長さmax
  /// </summary>
  const int kItemHeightMax = 720;

  /// <summary>
  /// 速さ
  /// </summary>
  const int kSpeedUpSpeed = 150;
}
/// <summary>
/// コンストラクタ
/// </summary>
SpeedUp::SpeedUp()
  : item_speed_up_x_(0)
  , item_speed_up_y_(0)
  , item_speed_up_speed_(0.0f)
  , item_speed_up_image_(0)
  , item_speed_up_width_(0)
  , item_speed_up_height_(0) {
}

/// <summary>
/// デストラクタ
/// </summary>
SpeedUp::~SpeedUp() {
}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
/// <param name="time"></param>
void SpeedUp::Initialize(float x, float y, float speed) {
  item_speed_up_x_ = x;
  item_speed_up_y_ = y;
  item_speed_up_speed_ = speed;

  if (item_speed_up_image_ != 0) {
    DeleteGraph(item_speed_up_image_);
  }

  //画像を読み込み,高さ幅を取得
  item_speed_up_image_ = LoadGraph(kSpeedUpImage);
  GetGraphSize(item_speed_up_image_, &item_speed_up_width_, &item_speed_up_height_);

  is_item_speed_up_out_of_screen_ = false;
  is_item_fire_ = false;
}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void SpeedUp::Update(float delta_time) {
  if(!is_item_speed_up_out_of_screen_) {
    item_speed_up_speed_ = kSpeedUpSpeed;
    item_speed_up_y_ += item_speed_up_speed_ * delta_time;

    // エネミーが画面外に出たかどうかをチェック
    if (item_speed_up_y_ >= kItemHeightMax) {
      is_item_speed_up_out_of_screen_ = true;


    }
  }
}

/// <summary>
/// 描画
/// </summary>
void SpeedUp::Render() {
  if (!is_item_speed_up_out_of_screen_) {
    DrawGraph(item_speed_up_x_, item_speed_up_y_, item_speed_up_image_, TRUE);
  }
}

/// <summary>
/// 種類取得
/// </summary>
/// <returns></returns>
ItemManager::ItemKind SpeedUp::GetItemKind() {
  return ItemManager::ItemKind::kSpeedUp;
}

/// <summary>
/// アイテム発射
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void SpeedUp::FireItem(float x, float y) {
  item_speed_up_x_ = x;
  item_speed_up_y_ = y;
  is_item_speed_up_out_of_screen_ = false;
  is_item_fire_ = true;
}

/// <summary>
/// x座標
/// </summary>
/// <returns></returns>
float SpeedUp::GetX() {
  return item_speed_up_x_;
}

/// <summary>
/// y座標
/// </summary>
/// <returns></returns>
float SpeedUp::GetY() {
  return item_speed_up_y_;
}

/// <summary>
/// アイテムが発射されたか設定
/// </summary>
/// <param name="is_ite_fire"></param>
void SpeedUp::SetItemFire(bool is_item_fire) {
  is_item_fire_ = is_item_fire;
  item_speed_up_y_ = kItemHeightMax;
}

/// <summary>
/// 外に出たかどうか
/// </summary>
/// <param name="is_item_out_of_screen"></param>
void SpeedUp::SetItemOutOfScreen(bool is_item_out_of_screen) {
  is_item_speed_up_out_of_screen_ = is_item_out_of_screen;
}

