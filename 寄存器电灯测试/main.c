void SystemInit(void)
{
	
}

int main(void )
{
	//开启时钟
	*(unsigned int*)((unsigned int )0x40021000+0x18) |= (0x1<<2);
	
	//关闭灯
	*(unsigned int*)((unsigned int )0x40010800+0x0c) |= (0x1<<1);
	*(unsigned int*)((unsigned int )0x40010800+0x0c) |= (0x1<<2);
	*(unsigned int*)((unsigned int )0x40010800+0x0c) |= (0x1<<3);
	
	//配置IO模式，推挽模式，50m	
	*(unsigned int*)((unsigned int)0x40010800+0x00) |= (0x3<<(4*1));
	*(unsigned int*)((unsigned int)0x40010800+0x00) |= (0x3<<(4*2));
	*(unsigned int*)((unsigned int)0x40010800+0x00) |= (0x3<<(4*3));
	
	//开启灯
	*(unsigned int*)((unsigned int )0x40010800+0x0c) &=~ (0x1<<1);
	*(unsigned int*)((unsigned int )0x40010800+0x0c) &=~ (0x1<<2);
	*(unsigned int*)((unsigned int )0x40010800+0x0c) &=~ (0x1<<3);
	
	while(1);
}

