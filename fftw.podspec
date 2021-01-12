Pod::Spec.new do |s|
  s.name = 'fftw'
  s.version = '3.3.9'
  s.license = { :type => 'GNU', :file => 'LICENSE' }
  s.summary = 'FFTW library'
  s.homepage = 'https://github.com/happy-health/ios-fftw'
  s.authors = { 'Haris Ali' => 'haris@happy.ai' }
  s.source = { :git => 'git@github.com:happy-health/ios-fftw.git', :tag => s.version }
  s.platform = :ios, '12.0'
  s.public_header_files = 'fftw/fftw3.h'
  s.static_framework = true
  s.source_files = 'Source/**/*.{h,swift}'
  s.libraries = 'fftw'
  s.vendored_library = 'libfftw.a'
end
