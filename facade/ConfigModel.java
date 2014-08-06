package com.xlf.facade;

public class ConfigModel {
	/**
	 * 是否需要生成表现层，默认true
	 */
        private boolean needGenPresentation = true;
        private boolean needGenBusiness = true;
        private boolean needGenDAO = true;
        
        public boolean isNeedGenPresentation()
        {
        	return needGenPresentation;
        }
        
        public void setNeedGenPresentation(boolean needGenPresentation)
        {
        	this.needGenPresentation = needGenPresentation;
        }
        
        public boolean isNeedGenBusiness()
        {
        	return needGenBusiness;
        }
        
        public void setNeedGenBusiness(boolean needGenBusiness)
        {
        	this.needGenBusiness = needGenBusiness;
        }
        
        public boolean isNeedGenDAO()
        {
        	return needGenDAO;
        }
        
        public void setNeedGenDAO(boolean needGenDAO)
        {
        	this.needGenDAO = needGenDAO;
        }    
}
