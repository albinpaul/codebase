from __future__ import print_function
class ClassTypeerror(RuntimeError):
	def __init__(self, arg):
		self.args = arg
	
class A():
	def __init__(self):
		self.foo = 'foo'

class B():
	def __init__(self, a):
		try:
			if not isinstance(a,A):
				self.a = a
			else:
				raise ClassTypeerror('This is not correct parameter')

		except ClassTypeerror :
		
			raise




a = A()
B(a)    # right
B('a')  # wrong