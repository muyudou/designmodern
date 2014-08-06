package com.xlf.facade;

public class Business {
    public void generate()
    {
 	   //从配置管理里获取相应的配置信息
 	   ConfigModel cm = ConfigManager.getInstance().getConfigData();
 	   if (cm.isNeedGenBusiness())
 		   System.out.println("正在生成业务层代码文件");
    }
}
