package com.xlf.bridge;

public class UrgencyMessage extends AbstractMessage{
    public UrgencyMessage(MessageImplementor impl)
    {
    	super(impl);
    }
    
    public void sendMessage(String message, String toUser)
    {
    	message = "加急："+message;
    	super.sendMessage(message, toUser);
    }
    
    /**
     * 扩展自己的新功能：监控某消息的处理过程
     * */
    public Object watch(String messageId)
    {
    	return null;
    }
}
