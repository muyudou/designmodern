package com.xlf.bridge;

/**
 * 桥接模式:将抽象部分与实现部分分离，使它们可以独立的变化
 * */
public class Client {
       public static void main(String[] args)
       {
    	   //创建具体实现对象
    	   MessageImplementor impl = new MessageSMS();
    	   AbstractMessage m = new CommonMessage(impl);  
    	   m.sendMessage("请喝一杯茶", "小李");
    	   
    	   m = new UrgencyMessage(impl);
    	   m.sendMessage("请喝一本茶", "小李");
    	   
    	   m = new SpecialUrgencyMessage(impl);
    	   m.sendMessage("请喝一本茶", "小李");
    	   
    	   impl = new MessageMobile();
    	   m = new CommonMessage(impl);
    	   m.sendMessage("请喝一杯茶", "小李");
    	   
    	   m = new UrgencyMessage(impl);
    	   m.sendMessage("请喝一本茶", "小李");
    	   
    	   m = new SpecialUrgencyMessage(impl);
    	   m.sendMessage("请喝一本茶", "小李");
       }
}
