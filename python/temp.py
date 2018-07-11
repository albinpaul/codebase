import time
from selenium import webdriver

driver = webdriver.Chrome('C://Users//Kattooparambil//Downloads//chromedriver_win32//chromedriver')
driver.get('http://www.google.com/xhtml');
time.sleep(5) # Let the user actually see something!
search_box = driver.find_element_by_name('q')
search_box.send_keys('ChromeDriver')
search_box.submit()
time.sleep(5) # Let the user actually see something!
driver.quit()