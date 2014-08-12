package com.xlf.template;

public class ConcreteClass1 extends AbstractTemplate {
    public void doPrimitiveOperation1()
    {
    	System.out.println("ConcreteClass1子类定义的原语操作1");
    }
    
    public void doPrimitiveOperation2()
    {
    	System.out.println("ConcreteClass1子类定义的原语操作2");
    }
    
    //子类又重写了hook方法
    public void hookOperation1()
    {
    	//super.hookOperation1();
    	System.out.println("ConcreteClass1子类重写的hook方法");
    }
}
