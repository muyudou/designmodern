package com.xlf.template;

public abstract class AbstractTemplate {
/*
 * 模板方法：定义算法骨架
 * */
	public final void templateMethod()
	{
		this.operation1();
		this.operation2();
		this.doPrimitiveOperation1();
		this.doPrimitiveOperation2();
		this.hookOperation1();
	}
	
	/**
	 * 具体操作1：算法的步骤，固定实现，而且子类不需要访问
	 * */
	private void operation1()
	{
		System.out.println("具体操作1");
	}
	
	/**
	 * 具体操作2：算法的步骤，固定实现，子类可能需要访问，也可以定义
	 * 为protected,不可以被覆盖的，因此是final
	 * */
	protected final void operation2()
	{
		System.out.println("具体操作2");
	}
	
	/**
	 * 具体的AbstractClass操作，子类的公共功能，但通常不是子类的公共功能
	 * */
	protected void CommonOperation()
	{
		System.out.println("子类的公共操作");
	}
	
	/**
	 * 原语操作1,2：算法的必要步骤，父类无法确定如何真正实现，需要子类来实现
	 * */
	protected abstract void doPrimitiveOperation1();
	protected abstract void doPrimitiveOperation2();
	
	/**
	 * 钩子操作,算法的步骤，不一定需要，提供默认实现，由子类选择并具体实现
	 * */
	protected void hookOperation1()
	{
		System.out.println("Hook操作提供的默认实现");
	}
}
