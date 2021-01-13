Pod::Spec.new do |s|
  s.name = 'fftw'
  s.version = '3.3.9'
  s.license = { :type => 'GNU', :file => 'LICENSE' }
  s.summary = 'FFTW library'
  s.homepage = 'https://github.com/happy-health/ios-fftw'
  s.authors = { 'Haris Ali' => 'haris@happy.ai' }
  s.source = { :git => 'git@github.com:happy-health/ios-fftw.git', :tag => s.version }
  s.platform = :ios, '12.0'
  s.static_framework = true
  s.source_files = 'Source/**/*.{h,swift}'
  s.swift_versions = ["5.0"]
  s.libraries = 'fftw'
  s.vendored_library = 'libfftw.a'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
end
