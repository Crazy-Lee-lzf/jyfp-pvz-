# 记忆游戏 (PVZ版本)

## 一、关卡设计

### 1. 冒险模式（闯关模式）

分4大关，每大关最后有一个BOSS。（不带排行榜，有商店，有作弊道具）

5s

|    关卡     | 地图大小 | 图片数量(张*每种) | 时间 |
| :---------: | :------: | :---------------: | :--: |
|    $1-1$    |  $2*2$   |       $2*2$       | $7$  |
|    $1-2$    |  $3*3$   |       $2*4$       | $15$ |
|    $1-3$    |  $4*4$   |       $4*4$       | $20$ |
|    $1-4$    |  $4*4$   |       $8*2$       | $30$ |
| $1-5(Boss)$ |  $4*4$   |       $8*2$       | $40$ |

4s

|    关卡     | 地图大小 | 图片数量(张*每种) | 时间 |
| :---------: | :------: | :---------------: | :---------: |
|    $2-1$    |  $5*5$   |    $ 4*4 + 4*2 $    | $40$ |
|    $2-2$    |  $5*5$   |      $12*2$       | $50$ |
|    $2-3$    |  $6*6$   |    $ 6*4 + 8*2 $    | $70$ |
|    $2-4$    |  $6*6$   |      $18*2$       | $85$ |
| $2-5(Boss)$ |  $6*6$   |      $18*2$       | $100$ |

3s

|    关卡     | 地图大小 | 图片数量(张*每种) | 时间  |
| :---------: | :------: | :---------------: | :---: |
|    $3-1$    |  $7*7$   |    $8*4 + 8*2$    | $150$ |
|    $3-2$    |  $7*7$   |      $24*2$       | $170$ |
|    $3-3$    |  $8*8$   |   $10*4 + 12*2$   | $210$ |
|    $3-4$    |  $8*8$   |      $32*2$       | $230$ |
| $3-5(Boss)$ |  $8*8$   |      $32*2$       | $250$ |

2s

|    关卡     | 地图大小 | 图片数量(张*每种) | 时间  |
| :---------: | :------: | :---------------: | :---: |
|    $4-1$    |  $9*9$   |   $14*4 + 12*2$   | $400$ |
|    $4-2$    |  $9*9$   |      $40*2$       | $450$ |
|    $4-3$    | $10*10$  |   $16*4 + 18*2$   | $500$ |
|    $4-4$    | $10*10$  |      $50*2$       | $560$ |
| $4-5(Boss)$ | $10*10$  |      $50*2$       | $600$ |

### 2.挑战模式（经典模式）

分五个版本：新手、简单、中级、困难、地狱

带排行榜(每个难度排行榜单独设置，保存在后台)

| 难度 | 地图大小 | 每个图片翻开时间 | 时间限制 |
| :--: | :------: | :--------------: | :------: |
| 新手 |  $2*2$   |       $5$        |  $10s$   |
| 简单 |  $4*4$   |       $4$        |  $30s$   |
| 中级 |  $6*6$   |       $3$        |  $120s$  |
| 困难 |  $8*8$   |       $2$        |  $300s$  |
| 地狱 | $10*10$  |      $1.5$       |  $600s$  |

## 二、商店&道具设计

阳光：可以看全部的卡五秒（期间不能点击，也不能使用其他道具）20金币

钉耙：可以自动翻开一对卡牌	10 金币

小推车：可以延长三十秒	100 金币

三种道具上限为9（可以通过修改存档文件超过界限）

金币可以通过通关获得（已经过了的关也可以）

注意: 第三关及以后的关卡才能使用道具

## 三、界面设计

### UI

最上方 欢迎$ XXX $ （玩家名） 右边切换用户按钮

中间四个按钮：闯关模式 商店 经典模式 结束游戏

菜单：返回主界面 排行榜 （经典模式的五个）背景音乐

冒险模式选择关卡界面，同一页的是同一大关，每个大关分五小关，通过一关才能显示下一关。每一关点击图片进入。

### 战斗界面（冒险模式）：

自制倒计时进度条：僵尸往房子走来，走到房子结束游戏,（僵尸吃掉了你的脑子）

右边三个道具，点击图片可以使用

## 四、登陆/注册

新的对话框 可以注册和登陆(存档文件在 players/里面)

密码有加密处理，单向加密(防止查看存档文件时看到密码明文)

点击静态文本可以切换当前是登陆还是注册模式

## 五、玩法设计

每次同样大小的关卡出现的图片可以完全不同（比如2*2一共两种图片，每次是哪两种是随机的）

闯关模式的有部分关卡可以出现四张图是完全相同，任意一对同时翻开都算成功（自定义模式也可以设置）

BOSS机制：每三十秒可以打乱剩下的卡牌
