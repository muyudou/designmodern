package com.xlf.bridge;

public class SpecialUrgencyMessage extends AbstractMessage{
    public SpecialUrgencyMessage(MessageImplementor impl)
    {
    	super(impl);
    }
    
    public void hurry(String messageId)
    {
    	
    }
    
    public void sendMessage(String message, String toUser)
    {
    	message = "特急："+message;
    	super.sendMessage(message, toUser);
    }
}
