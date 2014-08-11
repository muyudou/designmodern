package com.xlf.bridge;

/**
 * 定义抽象部分的接口
 * */
public abstract class AbstractMessage {
 /**
  * 持有一个实现部分的对象
  * */
	protected MessageImplementor impl;
	/**
	 * 构造方法，传入实现部分的对象
	 * */
	public AbstractMessage(MessageImplementor impl)
	{
	     this.impl = impl;	
	}
	
	/**
	 * 示例操作：实现一定的功能，可能药转调实现部分的具体实现方法
	 * */
	public void sendMessage(String message, String toUser)
	{
		impl.send(message, toUser);
	}
}
