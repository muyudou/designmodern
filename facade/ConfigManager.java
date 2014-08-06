package com.xlf.facade;

//实现为单例模式
public class ConfigManager {
       private static ConfigManager manager = null;
       private static ConfigModel cm = null;
       //构造函数是私有的
       private ConfigManager()
       {}
       
       public static ConfigManager getInstance()
       {
    	   if (manager == null)
    	   {
    		   manager = new ConfigManager();
    		   cm = new ConfigModel();
    	   }
    	   return manager;
       }
       
       //获取配置文件
       public ConfigModel getConfigData()
       {
    	   return cm;
       }
}
