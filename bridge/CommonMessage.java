package com.xlf.bridge;

public class CommonMessage extends AbstractMessage{
   public CommonMessage(MessageImplementor impl)
   {
	   super(impl);
   }
   
   public void sendMessage(String message, String toUser)
   {
	 super.sendMessage(message, toUser);
   }
}
