package com.xlf.facade;

public class DAO {
    public void generate()
    {
 	   //从配置管理里获取相应的配置信息
 	   ConfigModel cm = ConfigManager.getInstance().getConfigData();
 	   if (cm.isNeedGenDAO())
 		   System.out.println("正在生成数据层代码文件");
    }
}
