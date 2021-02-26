Pod::Spec.new do |s|
  s.name = 'HappyFFTW'
  s.version = '3.3.10'
  s.license = { :type => 'GNU General Public License', :file => 'LICENSE' }
  s.summary = 'FFTW library'
  s.homepage = 'https://github.com/happy-health/ios-fftw'
  s.authors = { 'Matteo Frigo' => 'athena@fftw.org', 'Steven G. Johnson' => 'stevenj@math.mit.edu' }
  s.source = { :git => 'https://github.com/happy-health/ios-fftw.git', :tag => s.version }
  s.platform = :ios, '12.0'
  s.static_framework = true
  s.source_files = 'Source/**/*.{h,swift}'
  s.swift_versions = ["5.0"]
  s.libraries = 'fftw'
  s.vendored_library = 'libfftw.a'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
end
