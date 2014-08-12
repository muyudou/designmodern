/**
 * 模板方法（类行为型模式）：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中，
 * templatemethod使得子类可以不改变一个算法的结构即可冲顶以该算法的某些特定步骤
 * */

package com.xlf.template;

public class Client {
    public static void main(String[] args)
    {
    	AbstractTemplate ac;
    	ac = new ConcreteClass1();
    	ac.templateMethod();
    	ac = new ConcreteClass2();
    	ac.templateMethod();
    }
}
