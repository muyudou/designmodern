package com.xlf.bridge;

/**定义实现部分的接口，可以与抽象部分接口的方法不一致
 */
public interface MessageImplementor {
   public void send(String message, String toUser);
}

