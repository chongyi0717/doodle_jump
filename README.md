# 2020-pd2-DoodleJump
## Video link
## How to play
按鍵A和D控制玩家移動
## Requirements
(1)玩家能自動跳且能在超過畫面邊界時從反方向出來  
(2)兩種跳板，一種能橫向移動，一種能在玩家踩到時消失  
(3)兩種道具，一種是彈簧，一種是彈簧床，踩到彈簧床時能比踩到彈簧時跳得更高  
(4)一只怪物，碰到後遊戲結束
(5)按下空格鍵能射出子彈消滅怪物  
(6)子彈射中怪物後怪物會從屏幕消失
(7)一個黑洞，碰到後遊戲結束  
(8)一個護盾，拿到後會在右上方顯示是否拿到護盾，反之則會消除，拿到後碰到怪物或黑洞遊戲繼續，消耗護盾  
(9)遊戲能夠無限遊玩，直到掉出屏幕或在沒有護盾的情況下碰到怪物  
(10)按下escape鍵能夠暫停遊戲
(11)遊戲進行是左上角會有數字顯示當前分數
(12)遊戲結束時會顯示“GAME OVER”字樣，同時顯示出當前遊戲的分數  
## Polymorphism
(13)以下的class繼承了PlatForm這個abstract class:  
#(a)PlatForm_Basic  
(b)PlatFormBroken  
(c)PlatFormMoving  
(d)PlatForm_Prop_Spring  
(e)PlatForm_Prop_SpringBed  
(f)Coin  
(g)Hazard  
(h)Monster  
在MainWindow中創建PlatForm指標的vector來存取所有子類型，同時對所有物件進行操作
## Bonus
(14)遊戲結束後能在結束界面顯示目前最高分  
(15)遊戲中能撿取金幣，數量會顯示在右上角，遊戲結束後會顯示撿拾的金幣總額
