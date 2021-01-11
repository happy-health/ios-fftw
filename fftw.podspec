Pod::Spec.new do |s|
  s.name = 'fftw'
  s.version = '0.0.1'
  s.summary = 'C algorithms library for MP product'
  s.homepage = 'https://github.com/happy-health/ios-fftw'
  s.license = { :type => 'Commercial', :text => 'Created and licensed by Happy Health, Inc. Copyright 2020 Happy Health, Inc. All rights reserved.' }
  s.authors = { 'Steve DiCristofaro' => 'steve@gideon.health', 'Haris Ali' => 'haris@happy.ai' }
  s.source = { :git => 'git@github.com:happy-health/ios-fftw.git', :tag => s.version.to_s }
  s.ios.deployment_target = '12.0'
  s.source_files = [
    'Source/**/*.{h,c,swift,mlmodel,mlmodelc}'
  ]
  s.swift_version = '5'
end
