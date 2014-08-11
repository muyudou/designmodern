package com.xlf.bridge;

public class MessageEmail  implements MessageImplementor{
    public void send(String message, String toUser)
    {
    	System.out.println("使用E-mail的方式，发送消息:"+message+
    			"给"+toUser);
    }
}

