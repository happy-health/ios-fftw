Pod::Spec.new do |s|
  s.name = 'HappyFFTW'
  s.version = '3.3.10-xcframework'
  s.license = { :type => 'GNU General Public License', :file => 'LICENSE' }
  s.summary = 'FFTW library'
  s.homepage = 'https://github.com/happy-health/ios-fftw'
  s.authors = { 'Matteo Frigo' => 'athena@fftw.org', 'Steven G. Johnson' => 'stevenj@math.mit.edu' }
  s.source = { :git => 'https://github.com/happy-health/ios-fftw.git', :tag => s.version }
  s.platform = :ios, '12.0'
  s.swift_versions = ["5.0"]
  s.cocoapods_version = '>= 1.11.2'
  s.vendored_frameworks = "HappyFFTW.xcframework"
end
