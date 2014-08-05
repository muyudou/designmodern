/* 策略模式
   支付工资的策略接口,将上下文作为参数传进去
 */

 interface PaymentStrategy {
    public void pay(PaymentContext ctx);
}

//人民币现金支
class RMBCash implements PaymentStrategy {
    public void pay(PaymentContext ctx)
    {
        System.out.println("现在给"+ctx.getUserName()
                +"人民币先进支付"+ctx.getMoney()+"元");
    }
}

 class DollarCash implements PaymentStrategy {
    public void pay(PaymentContext ctx)
    {
        System.out.println("现在给"+ctx.getUserName()
                +"美元现金支付"+ctx.getMoney()+"元");
    }
}

class PaymentContext {
    private String userName;
    private double money;
    private PaymentStrategy strategy;

    public PaymentContext(String userName, double money,
            PaymentStrategy strategy)
    {
        this.userName = userName;
        this.money = money;
        this.strategy = strategy;
    }

    public String getUserName()
    {
        return userName;
    }

    public double getMoney()
    {
        return money;
    }

    public void payNow()
    {
        this.strategy.pay(this);
    }
}

public class Client {
    public static void main(String[] args)
    {
        PaymentStrategy strategyRMB = new RMBCash();
        PaymentStrategy strategyDollar = new DollarCash();

        PaymentContext ctx1 = new PaymentContext("小李", 5000, 
                strategyRMB);
        ctx1.payNow();
        PaymentContext ctx2 = new PaymentContext("Petter", 8000, 
                strategyDollar);
        ctx2.payNow();
    }
}
